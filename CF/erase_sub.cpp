#include <string>
#include <iostream>
#include <fstream>

using namespace std;

#define NM 405

int pos[NM][NM];

int main()
{
	ifstream cin("erase_sub.in");
	int T; cin >> T;
	while (T--)
	{
		memset(pos, 0, sizeof(pos));
		string a,b;
		cin >> a >> b;
		int n = b.size();
		int m = a.size();

		pos[0][0] = 1;
		for (int i = 1; i <= n; ++i)
			for (int j = i; j <= m; ++j)
			{
				if (pos[i][j-1])  pos[i][j] = 1;
				if (pos[i-1][j-1] && b[i-1] == a[j-1]) pos[i][j] = 1;
			}

		if (pos[n][m]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}