#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

#define t first
#define l second.first
#define h second.second

int main()
{
	// ifstream cin("air.in");
	int T; cin >> T;
	while(T--)
	{
		int n, m; cin >> n >> m;
		vector <pair<int, pair<int, int> > > a;
		a.push_back(make_pair(0, make_pair(m,m)));
		for (int i = 1; i <= n; ++i)
		{
			int ti, li, hi;
			cin >> ti >> li >> hi;
			a.push_back(make_pair(ti, make_pair(li,hi)));
		}
		int ok = 1;
		for (int i = 1; i <= n; ++i)
		{
			int lt = a[i-1].t;
			int ct = a[i].t;
			int d = ct - lt;

			// cout << "diff " << d << endl; 

			int ll = a[i-1].l - d;
			int lh = a[i-1].h + d;

			int cl = a[i].l;
			int ch = a[i].h;

			int nl = max(ll, cl);
			int nh = min(lh, ch);

			// cout << i << ":" << nl << " " << nh << " " << ll << " " << lh << " " << endl;
			if (nl > nh) {ok = 0; break;}
			else a[i] = make_pair(ct, make_pair(nl, nh));
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}