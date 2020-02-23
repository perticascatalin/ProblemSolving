#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	// ifstream cin("three.in");
	int T; cin >> T;
	while(T--)
	{
		string a,b,c; cin >> a >> b >> c;
		int n = c.size();
		int ok = 1;
		for (int i = 0; i < n; ++i)
			if (c[i] != b[i] && a[i] != c[i]) ok = 0;
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	return 0;
}