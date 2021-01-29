#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	//ifstream cin ("qabc.in");
	//ofstream cout ("qabc.out");

	int T; cin >> T;
	while (T--)
	{
		int N; cin >> N;
		vector <int> A, B;
		for (int i = 0; i < N; ++i)
		{
			int a; cin >> a;
			A.push_back(a);
		}
		for (int i = 0; i < N; ++i)
		{
			int b; cin >> b;
			B.push_back(b);
		}

		for (int i = 0; i < N; ++i) B[i] -= A[i];

		int ok = 1;

		for (int i = 0; i < N; ++i) if (B[i] < 0) ok = 0;

		if (!ok) 
		{
			cout << "NIE" << "\n";
			break;
		}

		for (int i = 0; i < N - 2; ++ i)
			if (B[i] != 0)
			{
				int S = B[i];
				B[i] -= S;
				B[i+1] -= 2*S;
				B[i+2] -= 3*S;
				if (B[i+1] < 0 || B[i+2] < 0)
				{
					ok = 0;
					break;
				}
			}

		for (int i = 0; i < N; ++i) if (B[i] != 0) ok = 0;

		if (!ok) 
			cout << "NIE" << "\n";
		else
			cout << "TAK" << "\n";
	}

	return 0;
}