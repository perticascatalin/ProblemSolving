#include <iostream>
#include <fstream>

using namespace std;

int S[100];

int main() {
	// ifstream cin("dense_array.in");
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		for (int i = 1; i <= N; ++i) cin >> S[i];
		int sol = 0;
		for (int i = 1; i < N; ++i) {
			int a = max(S[i], S[i+1]);
			int b = min(S[i], S[i+1]);
			for (int j = 1; j <= 10; j++) {
				if ((double) a / (double) b <= (double) (1<<j)) {
					sol += (j-1);
					break;
				}
			}
		}
		cout << sol << "\n";
	}
	return 0;
}