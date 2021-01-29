#include <iostream>
#include <fstream> 
#include <cstring>

using namespace std;

#define nmax 200

int main()
{
	//ifstream cin ("chefprms.in");
	//ofstream cout ("chefprms.out");

	int T; cin >> T;

	int semiprimes[nmax + 1], primes[nmax + 1];
	memset (semiprimes, 0, sizeof(semiprimes));
	memset (primes, 1, sizeof(primes));

	primes[0] = 0;
	primes[1] = 0;
	for (int i = 2; i <= nmax; ++i)
		if (primes[i])
			for (int j = i*i; j <= nmax; j += i)
				primes[j] = 0;

	/*
	for (int i = 0; i <= nmax; ++i)
		if (primes[i]) cout << i << "\n"; */

	for (int i = 2; i <= nmax; ++i)
		if (primes[i])
			for (int j = i+1; j <= nmax; ++j)
				if (primes[j] && i*j <= nmax) semiprimes[i*j] = 1;

	while (T--)
	{
		int N; cin >> N;
		int ok = 0;
		for (int i = 0; i <= N; ++i)
			if (semiprimes[i] && semiprimes[N-i])
			{
				ok = 1;
				//cout << i << " " << N-i << "\n";
				break;
			}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}