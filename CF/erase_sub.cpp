#include <string>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#define NM 405

int pos[NM][NM];
int nxt[NM][NM];

int main()
{
	// ifstream cin("erase_sub.in");
	int T; cin >> T;
	while (T--)
	{
		string s,p;
		cin >> s >> p;
		int n = s.size();
		int m = p.size();

		int ok = 0;
		for (int k = 0; k <= m; ++k)
		{
			int maxa = k;
			int maxb = m-k;

			memset(pos, -1, sizeof(pos));
			memset(nxt, -1, sizeof(nxt));

			for (int i = 0; i < m; ++i)
			{
				for (int j = n-1; j >= 0; --j)
					if (p[i] == s[j]) nxt[j][p[i]-'a'] = j;
					else nxt[j][p[i]-'a'] = nxt[j+1][p[i]-'a'];
			}

			pos[0][0] = 0;
			for (int i = 0; i <= maxa; ++i)
				for (int j = 0; j <= maxb; ++j)
				{
					if (pos[i][j] == -1) continue;
					int l = pos[i][j];
					if (i < maxa && nxt[l][p[i]-'a'] != -1 && (pos[i+1][j] == -1 || nxt[l][p[i]-'a'] + 1 < pos[i+1][j])) 
						pos[i+1][j] = nxt[l][p[i]-'a'] + 1;

					if (j < maxb && nxt[l][p[k+j]-'a'] != -1 && (pos[i][j+1] == -1 || nxt[l][p[k+j]-'a'] + 1 < pos[i][j+1])) 
						pos[i][j+1] = nxt[l][p[k+j]-'a'] + 1;
				}
			if (pos[maxa][maxb] != -1) ok = 1;
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}