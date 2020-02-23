#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// ifstream cin("pixel.in");
	int T; cin >> T;
	while (T--)
	{
		int n, m, l, c;
		cin >> m >> n >> c >> l;
		int area = 0;
		// above
		if (l) area = max(area, l * m);
		// below
		if (l < n - 1) area = max(area, (n - l - 1) * m);
		// left
		if (c) area = max(area, c * n);
		// right
		if (c < m - 1) area = max(area, (m - c - 1) * n);
		cout << area << endl;
	}

	return 0;
}