#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#define fif first.first
#define fis first.second
#define sec second

int main()
{
	ifstream cin ("teme.in");
	ofstream cout ("teme.out");

	int T; cin >> T;
	while (T--)
	{
		int n; cin >> n;
		vector <pair<pair<int, int>, int> > dif_req_dead;
		for (int i = 0; i < n; ++i)
		{
			int r, d;
			cin >> r >> d;
			int dif = d - r;
			dif_req_dead.push_back(make_pair(make_pair(dif, r), d));
		}
		sort(dif_req_dead.begin(), dif_req_dead.end());
		/*
		for (int i = 0; i < n; ++i)
			cout << dif_req_dead[i].fif << " " << dif_req_dead[i].fis << " " << dif_req_dead[i].sec << "\n";
			*/
		int so_far = 0;
		int sup_max = 0;
		for (int i = 0; i < n; ++i)
		{
			so_far += dif_req_dead[i].fis;
			//cout << so_far << "\n";
			if (so_far > dif_req_dead[i].sec) sup_max = max(sup_max, so_far - dif_req_dead[i].sec);
		}
		cout << sup_max << "\n";
	}

	return 0;
}