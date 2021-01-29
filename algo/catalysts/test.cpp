#include <set>
//#include <iostream>
#include <fstream>

using namespace std;

#define NM 1005

set <int> st;
int v[NM][NM];

int main()
{
	ifstream cin ("level1_0.in");
	ofstream cout ("level1_0.out");

	int n,m;

	cin>>n>>m;

	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j) {
			cin >> v[i][j];
			st.insert(v[i][j]);
		}
	if (st.size() != 1)
	{
		for (set<int>::iterator it = st.begin(); it != st.end(); it++) 
			if (*it != 0) cout << *it << " ";
	}
	else cout << *st.begin();

	return 0;
}