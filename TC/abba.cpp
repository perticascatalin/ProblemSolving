#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ABBA
{
	public:
	string canObtain(string initial, string target)
	{
		int pos[1005][1005], inv[1005][1005];
		memset(pos, 0, sizeof(pos));
		memset(inv, 0, sizeof(inv));

		int n = initial.size();
		int m = target.size();
		if (m < n) return "Impossible";

		// for size N
		for (int i = 0; i < m; ++i)
		{
			if (i + n > m) break;
			string sub = target.substr(i, n);
			if (sub.compare(initial) == 0) pos[i][i+n-1] = 1;
			reverse(sub.begin(), sub.end());
			if (sub.compare(initial) == 0) inv[i][i+n-1] = 1;
		}

		// for size N + 1, up to M
		for (int sz = n + 1; sz <= m; ++sz)
			for (int i = 0; i + sz - 1 < m; ++i)
			{
				int j = i + sz - 1;
				if (pos[i][j-1] && target[j] == 'A') pos[i][j] = 1;
				if (inv[i][j-1] && target[j] == 'B') pos[i][j] = 1;
				if (target[i] == 'A' && inv[i+1][j]) inv[i][j] = 1;
				if (target[i] == 'B' && pos[i+1][j]) inv[i][j] = 1;
			}

		if (pos[0][m-1]) return "Possible";
		else return "Impossible";
	}
};

int main()
{
	ABBA run;
	cout << run.canObtain("B", "ABBA") << endl;
	cout << run.canObtain("AB", "ABB") << endl;
	cout << run.canObtain("BBBBABABBBBBBA", "BBBBABABBABBBBBBABABBBBBBBBABAABBBAA") << endl;
	return 0;
}