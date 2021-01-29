#include <set>
#include <vector>
#include <cmath>
//#include <iostream>
#include <fstream>

using namespace std;

#define NM 1005
#define eps 0.00000001

set <int> st;
int v[NM][NM];
int n,m;

pair<int, int> get_average(int x0, int y0, int x1, int y1) {
	int i,j,cnt=0;
	double sumlin=0, sumcol=0;
	for(i=x0;i<=x1;++i) {
		for(j=y0;j<=y1;++j) {
			sumlin += (i-0.5);
			sumcol += (j-0.5);
			++cnt;
		}
	}

	double clin = sumlin/(cnt);
	double ccol = sumcol/(cnt);
	if (abs(clin - int(clin)) < eps) clin -= 1;
	if (abs(ccol - int(ccol)) < eps) ccol -= 1;
	return make_pair(int(clin), int(ccol));
}

int main()
{
	ifstream cin ("level1_0.in");
	ofstream cout ("level1_0.out");

	cin>>n>>m;

	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j) {
			cin >> v[i][j];
			//st.insert(v[i][j]);
		}

	vector<pair<int,int> > ans;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (v[i][j])
			{
				int row = i;
				int col = j;
				int val = v[i][j];
				while (row <= n && v[row][col] == val) ++row;
				--row;
				while (col <= m && v[row][col] == val) ++col;
				--col;

				// get id, check >= 4 * 4
				if(row-i >= 3 && col-j >= 3) {
					pair<int, int> aux = get_average(i, j, row, col);
					ans.push_back(aux);
				}

				for (int lin = i; lin <= row; ++lin)
					for (int cl = j; cl <= col; ++cl)
						v[lin][cl] = 0;
			}

	sort(ans.begin(), ans.end());
	for(int i=0;i<ans.size();++i)
		cout << i << ' ' << ans[i].first << ' ' << ans[i].second << ' ';

	return 0;
}