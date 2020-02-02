#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	int T;
	// ifstream cin("sharp.in");
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector <int> a, inc_upto, inc_downto;

		for (int i = 0; i < n; ++i)
		{
			int num; cin >> num;
			a.push_back(num);

			inc_upto.push_back(0);
			inc_downto.push_back(0);
		}

		for (int i = 0; i < n; ++i)
		{
			if (a[i] >= i) inc_upto[i] = 1;
			else break;
		}

		int j = 0;
		for (int i = n-1; i >= 0; --i)
		{
			if (a[i] >= j) inc_downto[i] = 1;
			else break;
			++j;
		}

		int ok = 0;
		for (int i = 0; i < n; ++i)
		{
			if (inc_upto[i] && inc_downto[i]) {ok = 1; break;}
		}
		if (ok) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}