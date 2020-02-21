#include <iostream>
#include <fstream>

using namespace std;

#define LL long long

int main()
{
	// ifstream cin("national.in");
	int T; cin >> T;
	while(T--)
	{
		LL n,g,b; cin >> n >> g >> b;
		LL k = n/2;
		if (n % 2) k++;
		LL s = k/g;
		LL sol;
		if (k % g == 0)
		{
			sol = (s-1) * (g+b) + g;
			if ((s-1) * b < n/2) sol += (n/2 - (s-1) * b);
		}
		else
		{ 
			sol = s * (g+b) + (k % g);
			if (s * b < n/2) sol += (n/2 - s * b);
		}
		cout << sol << endl;
	}
	return 0;
}