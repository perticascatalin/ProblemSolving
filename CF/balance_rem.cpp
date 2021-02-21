#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int C[3];

int main() {
	// ifstream cin("balance_rem.in");
	int T; cin >> T;
	while (T--) {
		memset(C, 0, sizeof(C));
		int N; cin >> N; int A; int sol = 0;
		for (int i = 0; i < N; ++i) {
			cin >> A;
			++C[A%3];
		}
		int mini = min(C[0], min(C[1], C[2]));
		int maxi = max(C[0], max(C[1], C[2]));
		while (mini != maxi) {
			maxi = -1;
			int maxp = -1;

			for (int i = 0; i < 3; ++i) if (C[i] > maxi) {
				maxi = C[i];
				maxp = i;
			}

			int nextp = (maxp + 1) % 3;
			int to_add = (C[maxp] - N/3);
			sol += to_add;
			C[nextp] += to_add;
			C[maxp] = N/3;

			mini = min(C[0], min(C[1], C[2]));
			maxi = max(C[0], max(C[1], C[2]));
		}
		cout << sol << "\n";
	}

	return 0;
}