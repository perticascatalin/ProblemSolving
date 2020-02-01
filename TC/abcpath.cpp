#include <iostream>
#include <vector>
#include <string>

using namespace std;


class ABCPath
{
	public:
	int length(vector <string> grid)
	{
		int pl[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
		int pc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

		int n = grid.size();
		int m = grid[0].size();

		vector <vector<bool> > pos;
		vector<bool> tmpl;

		for (int i = 0; i < m; ++i) tmpl.push_back(false);
		for (int i = 0; i < n; ++i) pos.push_back(tmpl);

		vector < pair<char,char> > where[26];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				where[grid[i][j] - 'A'].push_back(make_pair(i,j));

		if (where[0].size() == 0) return 0;

		for (int i = 0; i < where[0].size();++i)
			pos[where[0][i].first][where[0][i].second] = true;

		for (int p = 1; p < 26; ++p)
		{
			if (where[p].size() == 0) return p;
			int found = 0;
			for (int i = 0; i < where[p].size();++i)
			{
				int l = where[p][i].first;
				int c = where[p][i].second;

				for (int k = 0; k < 8; ++k)
				{
					int nl = l + pl[k];
					int nc = c + pc[k];
					if (nl < 0 || nl >= n) continue;
					if (nc < 0 || nc >= m) continue;

					if (grid[nl][nc] + 1 == grid[l][c] && pos[nl][nc])
					{
						pos[l][c] = true;
						found = 1;
					}
				}
			}
			// cout << "Status for " << p << " " << found << endl;
			if (!found) return p;
		}
		return 26;
	}
};

int main()
{
	ABCPath run;
	vector <string> sample;
	sample.push_back("ABE");
	sample.push_back("CFG");
	sample.push_back("BDH");
	sample.push_back("ABC");
	cout << run.length(sample) << endl;
	return 0;
}