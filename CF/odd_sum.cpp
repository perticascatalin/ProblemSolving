#include <iostream>
#include <fstream>

using namespace std;

int A[2005];

int main()
{
	// ifstream cin("odd_sum.in");
	int T; cin >> T;
	while(T--)
	{
		int N;
		cin >> N;
		for (int i = 0; i < N; ++i) cin >> A[i];
		int has_even = 0;
		int has_odd = 0;
		for (int i = 0; i < N; ++i) 
			if (A[i] % 2) has_odd++;
			else has_even++;
		if (has_odd)
		{
			if (N % 2) cout << "YES" << endl;
			else if (has_even) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		else cout << "NO" << endl;
	}

	return 0;
}