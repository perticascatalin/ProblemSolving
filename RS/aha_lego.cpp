#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#define NM 55

int n, m;
int in[NM][NM], prize[NM][NM];
int estim[NM][NM];

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

int main()
{
	ifstream cin("aha_lego.in");
	int T; cin >> T;
	while (T--)
	{
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
			if (num_players > 0) avg = prize_sum/num_players;
			for (int i = 0; i < n; ++i) if (in[i][j]) estim[i][j] = avg; 
		}

		// print estim
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j) cout << estim[i][j] << " ";
			cout << endl;
		}

	}
	return 0;
}