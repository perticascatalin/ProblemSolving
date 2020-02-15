#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// #define eps 0.000000001

int main()
{
	// ifstream cin("rabbits.in");
	int T; cin >> T;
	while (T--)
	{
		int x,y,a,b;
		cin >> x >> y >> a >> b;
		double t = double (y-x) / double (a + b);
		// if (abs(t - int(t)) < eps) cout << t << endl;
		// else cout << -1 << endl;
		if ((y - x) % (a + b) == 0) cout << int(t) << endl;
		else cout << -1 << endl;
	}

	return 0;
}