#include <iostream>
#include <fstream>

using namespace std;

int A[100005];

int main()
{
	// ifstream cin("friend.in");
	int T; cin >> T;
	while (T--)
	{
		int n, x; cin >> n >> x;
		for (int i = 0; i < n; ++i) cin >> A[i];
		int found = 0;
		for (int i = 0; i < n; ++i) 
			if (A[i] == x)
			{
				cout << 1 << endl;
				found = 1;
				break;
			}
		if (found) continue;
		int maxi = 0;
		for (int i = 0; i < n; ++i) 
			maxi = max(maxi, A[i]);
		int sol = x/maxi;
		if (x % maxi) sol += 1;
		sol = max(2, sol); // in case maxi larger than x
		cout << sol << endl;
	}
	return 0;
}