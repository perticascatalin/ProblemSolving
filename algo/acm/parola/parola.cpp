#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define LMAX 1000005
#define NMAX 1000005

int main()
{
	ifstream cin("parola.in");
	ofstream cout("parola.out");

	int T;
	cin >> T;

	int count_so_far[NMAX];

	while (T--)
	{
		int N, K; string parola;

		cin >> N >> K;
		cin >> parola;

		//cout << parola << "\n";

		memset(count_so_far, 0, sizeof(count_so_far));
		count_so_far[0] = 1;
		int prev = 0;
		long long sol = 0;
		for (int i = 0; i < parola.size(); ++i)
		{
			int cur = (prev + parola[i]) % N;
			int sub = (cur - K + N) % N;
			sol += count_so_far[sub];
			count_so_far[cur]++;
			prev = cur;
		}
		cout << sol << "\n";
	}

	return 0;
}