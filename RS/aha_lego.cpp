#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

#define NM 55

int n, m;
int in[NM][NM], prize[NM][NM];
int estim[NM][NM];

// constantly updated data
int scored[NM], avail[NM];
int reprize[NM][NM];
int pprize[NM];


int players(int d)
{
	int num = 0;
	for (int i = 0; i < n; ++i) num += in[i][d];
	return num;
}

int prizes(int d)
{
	int num = 0;
	for (int i = 0; i < n; ++i) num += prize[i][d];
	return num;
}

int re_players(int d)
{
	int num = 0;
	for (int i = 0; i < n; ++i) if (!scored[i]) num += in[i][d];
	return num;
}

int re_prizes(int d)
{
	int num = 0;
	for (int i = 0; i < n; ++i) if (!scored[i]) num += reprize[i][d];
	return num;	
}

int main()
{
	ifstream cin("aha_lego.in");
	int T; cin >> T;
	while (T--)
	{
		// RS 1
		// read test
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> in[i][j];

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> prize[i][j];

		// compute estim
		for (int j = 0; j < m; ++j)
		{
			int num_players = players(j);
			int prize_sum = prizes(j);

			int avg = 0;
			if (num_players > 0) avg = prize_sum / num_players;
			for (int i = 0; i < n; ++i) if (in[i][j]) estim[i][j] = avg; 
		}

		// print estim
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j) cout << estim[i][j] << " ";
			cout << endl;
		}

		// RS 2
		// make permutations
		vector <int> perm;
		for (int i = 0; i < m; ++i) perm.push_back(i);
		do {
			cout << "====================" << endl;
			cout << "PERMUTATION: ";
			for (int i = 0; i < m; ++i) cout << perm[i] << " ";
			cout << endl;

			memset(pprize, 0, sizeof(pprize)); // players prizes
			memset(scored, 0, sizeof(scored)); // players scored
			memset(avail, 1, sizeof(avail));   // divisions available

			// leave out prizes by division
			list <int> leave_out[NM];

			// init reprize
			for (int i = 0; i < n; ++i)
				for (int j = 0; j< m; ++j)
					reprize[i][j] = prize[i][j];

			// reduce players in division perm[j]
			for (int j = 0; j < m; ++j)
			{
				int division = perm[j];

				// re-compute average for this division
				int prize_sum = re_prizes(division);
				int num_players = re_players(division);
				int avg = 0;
				if (num_players > 0) avg = prize_sum / num_players;

				// cout << "!!!! " << avg << endl;

				// put in pprize 
				for (int i = 0; i < n; ++i) if (in[i][division] && !scored[i]) pprize[i] = avg;

				avail[division] = 0; // mark division as unavialable
				// for all the divisions available, we need to push down prizes
				for (int d = 0; d < m; ++d)
					if (avail[d])
					{
						// for player in the current division, if prize in avail division & not scored
						// note: should not have prize if already scored
						for (int i = n - 1; i > 0; --i) // bottom-up
							if (in[i][division] && reprize[i][d] && !scored[i])
							{
								// for players in available division push down prize until current player
								int c_prize = reprize[i][d];
								for (int k = i + 1; k < n; ++k)
								{
									// if this player will be scored, then disregard
									if (in[k][division]) continue;
									// if this player was scored, then disregard
									if (scored[k]) continue;
									// if this player not in avail division, then disregard
									if (!in[k][d]) continue;
									int new_c_prize = reprize[k][d];
									reprize[k][d] = c_prize;
									c_prize = new_c_prize;
									if (c_prize == 0) break; // stop if nothing to push down
								}
								// if prizes left, put them in leave_out
								if (c_prize > 0) leave_out[d].push_front(c_prize);
							}
					}

				// mark players as scored
				for (int i = 0; i < n; ++i) if (in[i][division]) scored[i] = 1;
				// if no more player to score, stop
				int not_scored = 0;
				for (int i = 0; i < n; ++i) if (!scored[i]) ++not_scored;
				if (not_scored == 0) break;
			}

			cout << "PPRIZE: ";
			for (int i = 0; i < n; ++i) cout << pprize[i] << " ";
			cout << endl;

			// compute minimum prize per division
			int div_min[NM];
			memset(div_min, -1, sizeof(div_min));
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j)
					if (div_min[j] == -1 || div_min[j] > pprize[i]) div_min[j] = pprize[i];

			cout << "DIV_MINS: ";
			for (int d = 0; d < m; ++d) cout << div_min[d] << " ";
			cout << endl;

			// compute leave outs and permutation score
			int score = 0;
			cout << "DIV_LEFT_OUT: ";
			for (int d = 0; d < m; ++d)
			{
				// cout << "Div " << d << " leave out : ";
				// for (list<int>::iterator it = leave_out[d].begin(); it != leave_out[d].end(); ++it) cout << *it << " ";
				// cout << endl;
				if (leave_out[d].empty()) cout << "N ";
				else cout << leave_out[d].front() << " ";

				if ((!leave_out[d].empty() && div_min[d] >= leave_out[d].front()) || leave_out[d].empty()) ++score;
			}
			cout << endl;

			cout << "PERM SCORE: " << score << endl; 

		} while (next_permutation(perm.begin(), perm.end()));
	}
	return 0;
}