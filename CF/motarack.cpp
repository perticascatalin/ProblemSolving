#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

#define NM 100005

int A[NM];
int n;

int check(int num)
{
	vector <int> B;
	for (int i = 0; i < n; ++i)
		if (A[i] == -1) B.push_back(num);
		else B.push_back(A[i]);
	int maxd = 0;
	for (int i = 1; i < n; ++i) maxd = max(maxd, abs(B[i] - B[i-1]));
	return maxd;
}

int main()
{
	// ifstream cin("motarack.in");
	int T; cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> A[i];
		int m1_count = 0;
		for (int i = 0; i < n; ++i) if (A[i] == -1) ++m1_count;
		if (m1_count == n) 
		{
			cout << 0 << " " << 1 << endl;
			continue;
		}
		int mini = 1000000000;
		int maxi = 0;
		for (int i = 0; i < n; ++i) 
			if (A[i] != -1)
			{
				mini = min(mini, A[i]);
				maxi = max(maxi, A[i]);
			}

		int left = mini;
		int right = maxi;

		while (right - left >= 3)
		{
			int p = (right - left) / 3;
			int a = left + p;
			int b = right - p;
			int s1 = check(a);
			int s2 = check(b);
			if (s1 < s2) right = b;
			else left = a;
		}

		int sol = 1000000000;
		int k = left;
		for (int i = left; i <= right; ++i)
		{
			int s = check(i);
			if (s < sol)
			{
				sol = s;
				k = i;
			}
		}
		cout << sol << " " << k << endl;
	}
	return 0;
}