#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define NMAX 205
#define mod 1000000007

int main()
{
	ifstream cin("deceeu.in");
	ofstream cout("deceeu.out");

	int T;
	cin >> T;
	while (T--)
	{
		string A;
		long long answer = 0;
		cin >> A;
		int n = A.size();
		long long din[NMAX][NMAX];
		// 3, 4
		for (int s = 0; s < n; ++s)
		{
			//cout << s << "-----\n";
			memset(din, 0, sizeof(din));
			int maxi = s;
			int maxj = n - s - 2;
			for (int i = 0; i <= maxi; ++i)
			{
				for (int j = 0; j <= maxj; ++j)
				{
					din[i+1][j+1] = din[i][j+1] + din[i+1][j];
					if (din[i+1][j+1] > mod) din[i+1][j+1] -= mod;

					if (A[i] == A[j + s + 1]) din[i+1][j+1] += 1;
					else din[i+1][j+1] += (mod - din[i][j]);

					if (din[i+1][j+1] > mod) din[i+1][j+1] -= mod;

					if (A[i] == A[j + s + 1] && i == maxi) 
					{
						answer += (din[i][j] + 1);
						if (answer > mod) answer -= mod;
					}

					//cout << din[i+1][j+1] << " ";
				}
				//cout << "\n";
			}
		}
		cout << answer << "\n";
	}

	return 0;
}
