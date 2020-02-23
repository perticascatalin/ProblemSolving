#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define LL long long

LL cost[100005];

int main()
{
	ifstream cin("home.in");
	int T; cin >> T;
	while (T--)
	{
		int a, b, p; cin >> a >> b >> p;
		string S; cin >> S;
		int n = S.size();
		S = "0" + S;

		cost[n] = 0;
		if (S[n-1] == 'A') cost[n-1] = a;
		else cost[n-1] = b;
		for (int i = n-2; i >= 1; --i)
			if (S[i] != S[i+1])
			{
				if (S[i] == 'A') cost[i] = cost[i+1] + a;
				else cost[i] = cost[i+1] + b;
			}
			else
			{
				cost[i] = cost[i+1];
			}
		for (int i = 1; i <= n; ++i) cout << cost[i] << " ";
		cout << endl;
		int sol = n;
		for (int i = n; i >= 1; --i) 
			if (cost[i] <= p) sol = i;
		cout << sol << endl;
	}

	return 0;
}