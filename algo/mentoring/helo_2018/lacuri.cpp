#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

#define NMAX 105

ifstream cin ("lacuri.in");
ofstream cout ("lacuri.out");

int p_lin[4] = {-1, 0, 1, 0};
int p_col[4] = {0, 1, 0, -1};

int N, A[NMAX][NMAX], viz[NMAX][NMAX];
int teritory[NMAX * NMAX];
int num_lakes, square_num_lakes;
int lmin[NMAX * NMAX], lmax[NMAX * NMAX], cmin[NMAX * NMAX], cmax[NMAX * NMAX];

pair <int, int> prev_cell[NMAX][NMAX];
vector <pair<int, int> > path;
queue <pair<int, int> > Q;

// explore lake given initial position 
// mark explored, count teritory
void explore_lake(int lin, int col)
{
	// mark and count
	viz[lin][col] = num_lakes;
	teritory[num_lakes]++;

	// update min-max lin-col
	lmin[num_lakes] = min(lmin[num_lakes], lin);
	lmax[num_lakes] = max(lmax[num_lakes], lin);
	cmin[num_lakes] = min(cmin[num_lakes], col);
	cmax[num_lakes] = max(cmax[num_lakes], col);

	// explore in 4 directions
	for (int k = 0; k < 4; ++k)
	{
		int n_lin = lin + p_lin[k];
		int n_col = col + p_col[k];
		if (n_lin < 1 || n_lin > N) continue;
		if (n_col < 1 || n_col > N) continue;
		if (A[n_lin][n_col] && !viz[n_lin][n_col]) explore_lake(n_lin, n_col);
	}
}

// find lakes and mark them with 1, 2, 3 ... num_lakes 
void find_lakes()
{
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			if (A[i][j] && !viz[i][j])
			{
				++num_lakes;
				lmin[num_lakes] = N;
				cmin[num_lakes] = N;
				lmax[num_lakes] = 1;
				cmax[num_lakes] = 1;
				explore_lake(i, j);
			}
}

// check that all lakes are squares
int check_square()
{
	int ok = 1;
	for (int i = 1; i <= num_lakes; ++i)
		if ((lmax[i] - lmin[i] + 1) * (cmax[i] - cmin[i] + 1) != teritory[i] || (lmax[i] - lmin[i] + 1) != (cmax[i] - cmin[i] + 1))
		{
			//cout << lmin[i] << " " << lmax[i] << " " << cmin[i] << " " <<  cmax[i] << " " << teritory[i] << "\n";
			ok =  0;
		}
		else square_num_lakes++;
	return ok;
}

void find_min_path()
{
	Q.push(make_pair(1,1));
	viz[1][1] = 1;
	prev_cell[1][1] = make_pair(0,0);
	while (!Q.empty())
	{
		//cout << "while\n";
		pair <int,int> cell = Q.front();
		Q.pop();

		int lin = cell.first;
		int col = cell.second;
		// explore in 4 directions
		for (int k = 0; k < 4; ++k)
		{
			int n_lin = lin + p_lin[k];
			int n_col = col + p_col[k];
			if (n_lin < 1 || n_lin > N) continue;
			if (n_col < 1 || n_col > N) continue;
			if (!A[n_lin][n_col] && !viz[n_lin][n_col]) 
			{
				Q.push(make_pair(n_lin, n_col));
				viz[n_lin][n_col] = 1;
				prev_cell[n_lin][n_col] = make_pair(lin, col);
				//cout << lin << " " << col << "\n";
			}
		}
	}
	int lin = N;
	int col = N;
	if (viz[lin][col])
	{
		while (lin && col)
		{
			path.push_back(make_pair(lin, col));
			int n_lin = prev_cell[lin][col].first;
			int n_col = prev_cell[lin][col].second;
			lin = n_lin;
			col = n_col;
		}
	}
}

void read()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> A[i][j];
}

void print()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
			cout << A[i][j] << " ";
		cout << "\n";
	}
}

void print1()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
			cout << viz[i][j] << " ";
		cout << "\n";
	}
}

int main()
{
	read();
	//print();

	num_lakes = 0;
	square_num_lakes = 0;
	memset(viz, 0, sizeof(viz));
	memset(teritory, 0, sizeof(teritory));
	find_lakes();
	//print1 ();
	int ok_square = check_square();
	cout << square_num_lakes << "\n";

	if (!ok_square) return 0;
	//cout << "check passed\n";

	memset(viz, 0, sizeof(viz));
	find_min_path();
	reverse(path.begin(), path.end());
	for (int i = 0; i < path.size(); ++ i)
		cout << path[i].first << " " << path[i].second << "\n";

	return 0;
}
