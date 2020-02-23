#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	// ifstream cin("display.in");
	int seg[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	int T; cin >> T;
	while (T--)
	{
		int n; cin >> n;
		string sol = "";

		// only 7s and 1s
		if (n % 2)
		{
			sol = "7";
			n -= 3;
		}
		for (int i = 0; i < n; i += 2)
			sol = sol + "1";
		cout << sol << endl;
	}
	return 0;
}