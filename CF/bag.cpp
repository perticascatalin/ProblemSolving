#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#define LL long long

int D = 30;

int main()
{
	// ifstream cin("bag.in");
	int T; cin >> T;
	while (T--)
	{
		LL n, m;
		cin >> n >> m;
		LL counts[60];
		memset (counts, 0, sizeof(counts));
		for (int i = 1; i <= m; ++i)
		{
			int num; cin >> num;
			for (int j = 0; j < D; ++j)
				if (num & (1LL<<j)) counts[j]++;
		}

		// for (int i = 0; i < D; ++i) cout << counts[i] << " ";
		// cout << endl;

		int ok = 1;
		int sol = 0;
		for (LL j = 0; j < 2*D; ++j)
		{
			if (!(n & (1LL<<j)) ) continue;
			if (!ok) break;

			// cout << "Need " << j << endl;
			if (counts[j]) --counts[j];
			else
			{
				LL needed = (n & (1LL<<j));
				// try with smaller values
				LL avail = 0;
				for (LL i = j - 1; i >= 0; --i) avail += (counts[i] * (1LL<<i));

				// cout << "Avail vs needed: " << avail << " " << needed << endl;
				// can do with smaller values
				if (avail >= needed)
				{
					for (LL i = j - 1; i >= 0; --i)
						if (needed >= counts[i] * (1LL<<i))
						{
							needed -= counts[i] * (1LL<<i);
							counts[i] = 0;
						}
						else
						{
							LL sub = needed / (1LL<<i);
							needed -= (sub * (1LL<<i));
							counts[i] -= sub;
						}
				}
				// need to split larger values
				else
				{
					// cout << "Here we are" << endl;
					int found = 0;
					for (int i = j + 1; i < 2*D; ++i)
						if (counts[i])
						{
							found = 1;
							counts[i] -= 1;
							for (int k = i - 1; k >= j; --k) counts[k] = 1;
							sol += (i-j);
							// cout << "Added " << (i-j) << " to sol" << endl;
							// cout << j << " " << i << endl;
							break;
						}
					if (!found) ok = 0;
				}
			}
		}
		if (ok) cout << sol << endl;
		else cout << -1 << endl;
	}
	return 0;
}