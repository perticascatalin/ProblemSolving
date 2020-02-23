#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define NM 105

int A[2*NM];
int B[NM];
int used[2*NM];

int main()
{
	// ifstream cin("restore.in");
	int T; cin >> T;
	while (T--)
	{
		int n; cin >> n;

		memset (used, 0, sizeof(used));
		memset (A, 0, sizeof(A));

		for (int i = 1; i <= n; ++i) cin >> B[i];

		for (int i = 1; i <= n; ++i)
		{
			A[2*i-1] = B[i];
			used[B[i]]++;
		}
		// for (int i = 1; i <= 2*n; ++i) cout << A[i] << " ";
		// cout << endl;

		int ok = 1;
		for (int i = 1; i <= 2*n; ++i) if (used[i] > 1) ok = 0;
		if (!ok)
		{
			cout << -1 << endl;
			continue;
		}

		for (int i = 1; i <= 2*n; ++i)
			if (A[i] == 0)
			{
				int found = 0;
				for (int j = A[i-1] + 1; j <= 2*n; ++j) 
					if (used[j] == 0)
					{
						found = 1;
						A[i] = j;
						used[j]++;
						break;
					} 
				if (!found)
				{
					ok = 0;
					break;
				}
			}
		if (!ok)
		{
			cout << -1 << endl;
			continue;
		}
		else
		{
			for (int i = 1; i <= 2*n; ++i) cout << A[i] << " ";
			cout << endl;
		}
	}

	return 0;
}