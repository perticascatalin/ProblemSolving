#include <iostream>
#include <fstream>

using namespace std;

int A[105];

int main()
{
	// ifstream cin("haybales.in");
	int T; cin >> T;
	while (T--)
	{
		int n,d; cin >> n >> d;
		int d_left = d;
		for (int i = 0; i < n; ++i) cin >> A[i];
		int sol = A[0];
		for (int i = 1; i < n; ++i)
		{
			if (A[i] == 0) continue;
			if (d_left >= A[i] * i)
			{
				sol += A[i];
				d_left -= A[i] * i;
			}
			else
			{
				for (int j = A[i] - 1; j >= 0; --j)
					if (d_left >= j * i)
					{
						sol += j;
						d_left -= j * i;
						break;
					}
				break;
			}
		}
		cout << sol << endl;
	}
	return 0;
}