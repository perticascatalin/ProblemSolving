#include <iostream>
#include <fstream>

using namespace std;

#define NM 105

int T, N;
int A[NM];

int main()
{
	// ifstream cin("non_zero.in");
	cin >> T;
	while (T--)
	{
		int sol = 0;
		int sum = 0;
		cin >> N;
		for (int i = 0; i < N; ++i) 
		{
			cin >> A[i];
			if (A[i] == 0)
			{
				A[i] = 1;
				sol += 1;
			}
			sum += A[i];
		}
		if (sum == 0) sol += 1;
		cout << sol << endl;
	}

	return 0;
}