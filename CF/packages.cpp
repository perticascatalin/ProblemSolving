#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
	if (a.second < b.second) return true;
	if (a.second == b.second && a.first < b.first) return true;
	return false;
}

int main()
{
	// ifstream cin("packages.in");
	int T; cin >> T;
	while (T--)
	{
		int N; cin >> N;
		vector <pair<int,int> > P;
		for (int i = 0; i < N; ++i)
		{
			int x,y; cin >> x >> y;
			P.push_back(make_pair(x,y));
		}
		int not_pos = 0;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				if (P[i].second < P[j].second && P[i].first > P[j].first) not_pos = 1;
		if (not_pos) cout << "NO" << endl;
		else
		{
			string sol = "";
			P.push_back(make_pair(0,0));
			sort(P.begin(), P.end(), cmp);
			// for (int i = 0; i <= N; ++i)
			// 	cout << P[i].first << " " << P[i].second << endl;
			for (int i = 1; i <= N; ++i)
			{
				if (P[i].second != P[i-1].second)
				{
					if (P[i].first != P[i-1].first)
						for (int j = P[i-1].first; j < P[i].first; ++j) sol += "R";

					for (int j = P[i-1].second; j < P[i].second; ++j) sol += "U";
				}
				else
				{
					for (int j = P[i-1].first; j < P[i].first; ++j) sol += "R";
				}
			}
			cout << "YES" << endl;
			cout << sol << endl;
		}
	}
	return 0;
}