#include <iostream>
#include <fstream>

using namespace std;

#define NM 105

int A[NM], D[NM], N;

void find_depth(int left, int right, int d) {
	int amax, pos;
	amax = -1;
	for (int i = left; i <= right; ++i)
		if (A[i] > amax) {
			amax = A[i];
			pos = i;
		}
	D[pos] = d;
	if (pos - 1 >= left) find_depth(left, pos - 1, d + 1);
	if (pos + 1 <= right) find_depth(pos + 1, right, d + 1);
}

int main() {
	// ifstream cin("perm_transf.in");
	int T; cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; ++i) cin >> A[i];
		find_depth(1, N, 0);
		for (int i = 1; i <= N; ++i) cout << D[i] << " ";
		cout << "\n";
	}
	return 0;
}