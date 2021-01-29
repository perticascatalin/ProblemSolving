#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>

using namespace std;

#define NMAX 100005

int A[NMAX], up_to[NMAX], down_to[NMAX];

int main()
{
	//ifstream cin ("cardmgk.in");
	//ofstream cout ("cardmgk.out");

	int T; cin >> T;
	while (T--)
	{
		int N; cin >> N;
		for (int i = 1; i <= N; ++i)
			cin >> A[i];

		memset (up_to, 0, sizeof(up_to));
		memset (down_to, 0, sizeof(down_to));
		A[0] = 0; A[N + 1] = 2000000000;

		up_to[0] = 1;
		int i = 1;

		while (i <= N && A[i-1] <= A[i])
		{
			up_to[i] = 1;
			i++;
		}

		down_to[N+1] = 1;
		i = N;
		while (i >= 0 && A[i] <= A[i+1])
		{
			down_to[i] = 1;
			i--;
		}

		if (up_to[N] == 1) cout << "YES\n";
		else
		{
			int found = 0;
			for (int i = 1; i < N; ++i)
			{
				int ok = 1;
				if (!down_to[i+1]) ok = 0;
				if (!up_to[i]) ok = 0;
				if (A[1] < A[N]) ok = 0;
				if (ok)
				{
					found = 1;
					cout << "YES\n";
					break;
				}
			}
			if (!found) cout << "NO\n";
		}
	}

	return 0;
}