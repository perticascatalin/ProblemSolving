#include <iostream>
#include <fstream>

using namespace std;

#define LL long long

LL cube(LL n) {return n * n * n;}

int main() {
	// ifstream cin("sum_of_cubes.in");

	int T; cin >> T;
	while (T--) {
		LL N, M, n, m, X;
		LL limit = 10000;
		cin >> X;
		int found = 0;

		for (n = 1; n <= limit; ++n){
			N = cube(n); if (N >= X) break;
			M = (X-N);

			LL left, right;
			left = 1; right = limit;

			while (left < right) {
				LL mid = (left + right)/2;
				if (cube(mid) < M) left = mid + 1;
				else right = mid;
			}
			if (cube(left) == M) found = 1;
		}
		if (found) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}