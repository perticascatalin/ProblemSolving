#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#define MOD 1000000007
#define LL long long

vector <LL> A;

int main()
{
	ifstream cin ("galagie.in");
	ofstream cout ("galagie.out");

	int N; cin >> N;
	for (int i = 0; i < N; ++i)
	{
		LL a; cin >> a;
		A.push_back(a);
	}
	sort(A.begin(), A.end());

	LL cost = 0;
	LL partial = A[0];
	LL num = 1;
	for (int i = 1; i < N; ++i)
	{
		cost = (cost + (num * A[i]) % MOD - partial + MOD) % MOD;
		num++;
		partial = (partial + A[i]) % MOD;
	}
	partial = A[N - 1];
	num = 1;
	for (int i = N - 2; i >= 0; i--)
	{
		cost = (cost + partial - (num * A[i]) % MOD + MOD) % MOD;
		num++;
		partial = (partial + A[i]) % MOD;
	}
	cout << cost;

	return 0;
}