#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
    
using namespace std;

#define NM 2005
#define inf 4000005

int dp[NM][NM], last[NM][NM], mto[NM], ml[NM];

class ArraySorting
{
	public:
	vector <int> arraySort(vector<int> A)
	{
		vector <int> sol;
		int N = A.size();
		int M = 2000;
		reverse(A.begin(), A.end());

		memset(last, 0, sizeof(last));

		for (int i = 0; i <= N; ++i)
			for (int j = 0; j <= M; ++j)
				dp[i][j] = inf;

		dp[0][2000] = 0; last[0][2000] = -1;
		mto[2001] = inf; ml[2001] = 0;
		for (int j = M; j >= 1; --j)
		{
			mto[j] = dp[0][j];
			ml[j] = last[0][j];
			if (mto[j+1] < mto[j])
			{
				mto[j] = mto[j+1];
				ml[j] = ml[j+1];
			}
		}

		for (int i = 1; i <= N; ++i)
		{
			for (int j = M; j >= 1; --j)
			{
				dp[i][j] = mto[j];
				last[i][j] = ml[j];
				if (j != A[i-1]) ++dp[i][j];
			}
			for (int j = M; j >= 1; --j)
			{
				mto[j] = dp[i][j];
				ml[j] = j;
				if (mto[j+1] < mto[j])
				{
					mto[j] = mto[j+1];
					ml[j] = ml[j+1];
				} 
			}
		}

		int best = inf;
		for (int j = 1; j <= M; ++j)
			if (dp[N][j] < best) best = dp[N][j];
		for (int j = 1; j <= M; ++j)
			if (dp[N][j] == best)
			{
				int ind = N;
				int val = j;
				while (ind)
				{
					sol.push_back(val);
					val = last[ind][val];
					--ind;
				}
				break;
			}
		// reverse(sol.begin(), sol.end());
		return sol;
	}
};

int main()
{
	vector <int> A;
	A.push_back(3);
	A.push_back(7);
	A.push_back(7);
	A.push_back(7);
	A.push_back(6);
	ArraySorting run;
	vector <int> sol = run.arraySort(A);
	for (int i = 0; i < sol.size(); ++i) cout << sol[i] << endl;
	return 0;
}