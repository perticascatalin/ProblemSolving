#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define NM 200005
#define LL long long

LL A[NM], T[NM];
int used[NM];
vector <int> sp;

bool cmp(int i, int j)
{
	if (A[i] > A[j]) return true;
	if (A[i] == A[j] && T[i] <= T[j]) return true;
	return false;
}

int main()
{
	ifstream cin("rec.in");
	int N; cin >> N;

	for (int i = 0; i < N; ++i) cin >> A[i];
	for (int i = 0; i < N; ++i) cin >> T[i];

	memset(used, 0, sizeof(used));
	for (int i = 0; i < N; ++i) sp.push_back(i);
	sort(sp.begin(), sp.end(), cmp);

	priority_queue <pair<LL, int> > times;
	for (int i = 0; i < N - 1; ++i)
		if (T[sp[i]] > T[sp[i+1]])
		{
			// (-A[sp[i]] + x) * T[sp[i]] > (-A[sp[i+1]] + x) * T[sp[i+1]]
			// x + T[sp[i]] - x * T[sp[i+1]] > A[sp[i]] * T[sp[i]] - A[sp[i+1]] * T[sp[i+1]]
			LL x = (A[sp[i]] * T[sp[i]] - A[sp[i+1]] * T[sp[i+1]])/(T[sp[i]] - T[sp[i+1]]);
			if ((A[sp[i]] * T[sp[i]] - A[sp[i+1]] * T[sp[i+1]]) % (T[sp[i]] - T[sp[i+1]])) --x;
			times.push(make_pair(-x, i));
			// cout << A[sp[i]] << " " << A[sp[i+1]] << " at x = " << x << endl; 
		}

	LL sol = 0;
	int index = N-1;
	for (LL x = 1; x <= 2000000000; ++x)
	{
		int ok = 1;
		while (ok)
		{
			ok = 0;
			pair <LL, int> t;
			if (!times.empty())
			{
			 	t = times.top();
				if (-t.first <= x) // at a previous time
				{
					int ind = t.second;
					if (!used[sp[ind+1]])
					{
						int aux = sp[ind];
						sp[ind] = sp[ind+1];
						sp[ind+1] = aux;
						if (ind >= 1 && T[sp[ind-1]] > T[sp[ind]])
						{
							LL y = (A[sp[ind-1]] * T[sp[ind-1]] - A[sp[ind]] * T[sp[ind]])/(T[sp[ind-1]] - T[sp[ind]]);
							if ((A[sp[ind-1]] * T[sp[ind-1]] - A[sp[ind]] * T[sp[ind]]) % (T[sp[ind-1]] - T[sp[ind]])) --y;
							times.push(make_pair(-y, ind-1));			
						}
					}
					times.pop();
					ok = 1;
				}
			}
		}
		if (A[sp[index]] > x)
		{
			x = A[sp[index]] - 1;
			continue;
		}
		else
		{
			sol += (x - A[sp[index]]) * T[sp[index]];
			used[sp[index]] = 1;
			index--;
		}
		if (index < 0) break;
	}

	cout << sol << endl;
	return 0;
}