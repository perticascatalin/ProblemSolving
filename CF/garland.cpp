#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define NM 105
#define MAX 1000000000

int A[NM], dp[NM][NM][NM][2];

int main()
{
	// ifstream cin("garland.in");

	int N; cin >> N;
	for (int i = 1; i <= N; ++i) cin >> A[i];

	int num_even = N/2;
	int num_odd = N - num_even;
	for (int i = 1; i <= N; ++i)
	{
		if (A[i] == 0) continue;
		if (A[i] % 2) num_odd--;
		else num_even--;
	}

	// cout << num_even << " " << num_odd << endl;
	memset(dp, 64, sizeof(dp));
	dp[0][num_even][num_odd][0] = 0;
	dp[0][num_even][num_odd][1] = 0;

	int parity;
	for (int i = 1; i <= N; ++i)
		for (int evens = 0; evens <= num_even; ++evens)
			for (int odds = 0; odds <= num_odd; ++odds)
				for (int p = 0; p <= 1; ++p)
				{
					if (A[i] != 0)
					{
						parity = A[i] % 2;
						if (parity == p) dp[i][evens][odds][p] = min(
								dp[i-1][evens][odds][p], 
								dp[i-1][evens][odds][!p] + 1);
					}
					else
					{
						parity = p;
						dp[i][evens][odds][p] = min(
								dp[i-1][evens+!p][odds+p][p], 
								dp[i-1][evens+!p][odds+p][!p] + 1);
					}
				}

	cout << min(dp[N][0][0][0],dp[N][0][0][1]) << endl;
	return 0;
}