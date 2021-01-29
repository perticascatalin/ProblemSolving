#include <iostream>
#include <fstream>

using namespace std;

#define MOD 2011
#define NM 1000005

int dp[NM][2], ps[NM][2];

int get_ps(int a, int b, int sign)
{
	if (a == 0) return ps[b][sign];
	else return (ps[b][sign] - ps[a-1][sign] + MOD) % MOD;
}

int main()
{
	ifstream cin ("minusk.in");
	ofstream cout ("minusk.out");

	int N; int K;
	cin >> N; cin >> K;
	dp[0][0] = 1;
	dp[0][1] = 1;
	ps[0][0] = 1;
	ps[0][1] = 1;

	for (int i = 1; i <= N; ++i)
	{
		dp[i][0] = get_ps(max(0, i - K + 1), i - 1, 1);
		dp[i][1] = get_ps(0, i - 1, 0);
		ps[i][0] = (ps[i - 1][0] + dp[i][0]) % MOD;
		ps[i][1] = (ps[i - 1][1] + dp[i][1]) % MOD;
	}

	cout << (dp[N][0] + dp[N][1]) % MOD;

	return 0;
}