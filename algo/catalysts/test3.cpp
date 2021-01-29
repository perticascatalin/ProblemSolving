#include <fstream>
#include <vector>

using namespace std;

#define epsilon 0.000001

int main()
{
	ifstream cin ("level1_0.in");
	ofstream cout ("level1_0.out");

	int T; cin >> T;
	while (T--)
	{
		double a0, b0, a1, b1, r;
		cin >> a0 >> b0 >> a1 >> b1;
		a0 += 0.5;
		b0 += 0.5;
		a1 += 0.5;
		b1 += 0.5;
		vector <pair<int, int> > cells;
		for (double r = 0.0; r <= 1.0; r += epsilon)
		{
			double a = a0 * (1.0 - r) + a1 * r;
			int pa = int(a);
			double b = b0 * (1.0 - r) + b1 * r;
			int pb = int(b);
			//cout << pa << " " << pb << "\n";
			if (cells.size() == 0 || (pa != cells.back().first || pb != cells.back().second) )
				cells.push_back(make_pair(pa,pb));
		}
		for (int i = 0; i < cells.size(); ++i) cout << cells[i].first << " " << cells[i].second << " ";
		cout << "\n";
	}

	return 0;
}