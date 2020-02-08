#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1000000001

int main()
{
	int T;
	// ifstream cin("mind.in");
	cin >> T;
	while(T--)
	{
		int n,m,k;
		cin >> n >> m >> k;
		vector <int> a;
		for (int i = 0; i < n; ++i)
		{
			int num; cin >> num;
			a.push_back(num);
		}
		k = min(k, m - 1);
		int to_pick = n - k;
		int to_elim = m - k - 1;
		int to_pick_2 = to_pick - to_elim;

		int maxima = 0;
		for (int i = 0; i < n; ++i)
		{
			int j = i + to_pick - 1;
			if (j > n - 1) break;
			int minima = MAX;

			for (int k = i; k <= j; ++k)
			{
				int l = k + to_pick_2 - 1;
				if (l > j) break;
				minima = min(minima, max(a[k], a[l]));
			}
			maxima = max(maxima, minima);
		}
		cout << maxima << endl;
	}
	return 0;
}