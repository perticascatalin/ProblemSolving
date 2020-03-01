#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define NM 1000005
#define M  500000
#define LL long long

LL best[NM];
int B[NM];

int main()
{
	ifstream cin("journey.in");
	int N; cin >> N;
	for (int i = 1; i <= N; ++i) cin >> B[i];
	memset(best, 0, sizeof(best));
	for (int i = 1; i <= N; ++i) best[B[i] - i + M] += B[i];
	LL sol = 0;
	for (int i = 0; i <= 1000000; ++i) sol = max(sol, best[i]);
	cout << sol << endl;

	return 0;
}