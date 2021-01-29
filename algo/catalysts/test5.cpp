#include <set>
#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

#define NM 1005
#define eps 0.00000001

set<pair<int,int> > st[NM*NM];

int v[NM][NM];
int n,m,s;

int compx[NM][NM], wset[NM][NM];

int sexy_component[NM][NM];
int nsexy = 0;

pair<int, int> get_average(int comp) {
	int i,j;
	int cnt = 0;
	double sumlin=0, sumcol=0;
	int x0 = 10000; int y0 = 10000;
	int x1 = -1; int y1 = -1; 
	for (set<pair<int, int> >::iterator it = st[comp].begin(); it != st[comp].end(); ++it)
	{
		i = (*it).first;
		j = (*it).second;
		cout << i << ' ' << j << '\n';
		x0 = min(x0, i);
		y0 = min(y0, j);
		x1 = max(x1, i);
		y1 = max(y1, j);
		sumlin += (i-0.5);
		sumcol += (j-0.5);
		++cnt;
	}
	double clin = sumlin/(cnt);
	double ccol = sumcol/(cnt);
	if (abs(clin - int(clin)) < eps) clin -= 1;
	if (abs(ccol - int(ccol)) < eps) ccol -= 1;
	if (compx[int(clin)][int(ccol)] != compx[st[comp].begin()->first][st[comp].begin()->second]) 
		return make_pair(-1,-1);

	//cout << x0 << " " << y0 << " " << x1 << " " << y1 << "\n";
	sumlin=0, sumcol=0, cnt = 0;
	for(i=x0;i<=x1;++i) {
		for(j=y0;j<=y1;++j) {
			sumlin += (i-0.5);
			sumcol += (j-0.5);
			++cnt;
		}
	}

	clin = sumlin/(cnt);
	ccol = sumcol/(cnt);
	if (abs(clin - int(clin)) < eps) clin -= 1;
	if (abs(ccol - int(ccol)) < eps) ccol -= 1;
	if (compx[int(clin)][int(ccol)] != compx[st[comp].begin()->first][st[comp].begin()->second]) 
		return make_pair(-1,-1);
	return make_pair(int(clin), int(ccol));
}

int ncompx = 0;
int pl[] = {-1, 0, 1, 0};
int pc[] = {0, 1, 0, -1};

void fill(int lin, int col)
{
	compx[lin][col] = ncompx;
	for (int k = 0; k < 4; ++k)
	{
		int nlin = lin + pl[k];
		int ncol = col + pc[k];
		if (nlin <= 0 || nlin > n) continue;
		if (ncol <= 0 || ncol > m) continue;
		if (!compx[nlin][ncol] && v[nlin][ncol] == v[lin][col])
			fill(nlin, ncol);
	}
}

void fills(int lin, int col)
{
	sexy_component[lin][col] = nsexy;
	st[nsexy].insert(make_pair(lin, col));
	for (int k = 0; k < 4; ++k)
	{
		int nlin = lin + pl[k];
		int ncol = col + pc[k];
		if (nlin <= 0 || nlin > n) continue;
		if (ncol <= 0 || ncol > m) continue;
		if (compx[lin][col] == compx[nlin][ncol] && wset[nlin][ncol] && !sexy_component[nlin][ncol])
			fills(nlin, ncol);
	}
}

int main()
{
	ifstream cin ("level1_0.in");
	ofstream cout ("level1_0.out");

	cin>>n>>m>>s;

	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j) {
			cin >> v[i][j];
		}

	for (int i = 1;i<=n; ++i)
		for (int j = 1; j<=m;++j)
			if (v[i][j] && !compx[i][j])
			{
				ncompx++;
				fill(i,j);
			}

	vector<pair<int,int> > ans;
	int n_comp = 0;
	for (int i = 1; i <= n - s + 1; ++i)
		for (int j = 1; j <= m - s + 1; ++j)
			if (v[i][j])
			{
				int comp = wset[i][j];
				int val = v[i][j];
				int ok = 1;
				for (int lin = i; lin < i + s; ++lin)
				{
					if (!ok) break;
					for (int col = j; col < j + s; ++col)
						if (v[lin][col] != val) 
						{
							ok = 0;
							break;
						}
				}

				if (!ok) continue;

				if (comp == 0) 
				{
					n_comp++;
					comp = n_comp;
				}

				for (int lin = i; lin < i + s; ++lin)
					for (int col = j; col < j + s; ++col)
					{
						wset[lin][col] = comp;
						//st[comp].insert(make_pair(lin, col));
					}
			}

			
	for (int i = 1; i <=n; ++i)
		for (int j = 1; j <= m; ++j)
			if (!sexy_component[i][j] && wset[i][j])
			{
				nsexy++;
				fills(i,j);
			}


	for (int i = 1; i <= n; ++i)
	{
		for (int j =1 ; j<= m; ++j)
			cout << sexy_component[i][j] << " ";
		cout << "\n";
	}

	for (int i = 1; i <= nsexy; ++i)
	{
		pair<int, int> aux = get_average(i);
		if (aux != make_pair(-1,-1)) 
			ans.push_back(aux);

	}
	sort(ans.begin(), ans.end());
	for(int i=0;i<ans.size();++i)
		cout << i << ' ' << ans[i].first << ' ' << ans[i].second << ' ';

	return 0;
}