#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// ifstream cin("aose.in");
	int T; cin >> T;
	while (T--)
	{
		int a, b; cin >> a >> b;
		if (a == b) cout << 0 << endl;
		else
		{
			if (a < b && (b - a) % 2) cout << 1 << endl;
			if (a < b && (b - a) % 2 == 0) cout << 2 << endl;
			if (a > b && (a - b) % 2 == 0) cout << 1 << endl;
			if (a > b && (a - b) % 2) cout << 2 << endl;
		}
	}

	return 0;
}