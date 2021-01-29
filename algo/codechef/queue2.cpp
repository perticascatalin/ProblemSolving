#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define inf 2000000000

int main()
{
	//ifstream cin("queue2.in");
	//ofstream cout("queue2.out");

	int T; cin >> T;
	while (T--)
	{
		int N, M, K, L;
		cin >> N >> M >> K >> L;

		vector <int> A;
		A.push_back(0);
		A.push_back(K);
		for (int i = 0; i < N; ++i)
		{
			int a; cin >> a;
			A.push_back(a);
		}
		sort (A.begin(), A.end());
		int next_opening = M * L + L;
		int best = inf;
		for (int i = 1; i <= N + 1;)
		{
			int a = A[i-1] + 1;
			int b = A[i];
			int cur_best = inf;
			if (next_opening < a)
				cur_best = min(cur_best, a - next_opening);
			else if (next_opening > b)
				cur_best = min(cur_best, next_opening - b);
			else cur_best = min(cur_best, 0);
			best = min(best, cur_best);
			next_opening += L;
			while (i < N + 1 && A[i] == A[i+1]) ++i;
			++i;
		}
		cout << best << "\n";
	}

	return 0;
}