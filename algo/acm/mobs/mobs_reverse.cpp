#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

#define NMAX 100005

int TA[NMAX], TB[NMAX];
long long SA[NMAX], SB[NMAX];

int possible(int t_mid, int m, int N)
{
	// check if possible with t_mid
	int left = 1;
	int right = N - m;
	while (left < right - 1)
	{
		int mid = (left + right)/2;
		if (SB[N - m] - SB[mid-1] <= t_mid) right = mid;
		else left = mid + 1;
	}
	int kills_B = 0;
	if (SB[N - m] - SB[left-1] <= t_mid) kills_B = N - m - left + 1;
	else if (SB[N - m] - SB[right - 1] <= t_mid) kills_B = N - m - right + 1;

	left = 1;
	right = N - m - kills_B;
	while (left < right - 1)
	{
		int mid = (left + right)/2;
		if (SA[N - m - kills_B] - SA[mid-1] <= t_mid) right = mid;
		else left = mid + 1;
	}
	int kills_A = 0;
	if (SA[N - m - kills_B] - SA[left-1] <= t_mid) kills_A = N - m - kills_B - left + 1;
	else if (SA[N - m - kills_B] - SA[right - 1] <= t_mid) kills_A = N - m - kills_B - right + 1;

	if (kills_A + kills_B == N - m) return 1;
	return 0;
}

int main()
{
	ifstream cin ("mobs_gen.in");
	ofstream cout ("mobs.out");

	int T;
	cin >> T;
	while (T--)
	{
		int N, A, B;
		vector <int> H;
		cin >> N >> A >> B;
		if (A > B)
		{
			int aux = A;
			A = B;
			B = aux;
		}
		for (int i = 0; i < N; ++i)
		{
			int h;
			cin >> h;
			H.push_back(h);
		}
		H.push_back(0);
		sort(H.begin(), H.end());
		//for (int i = 1; i <= N; ++i) cout << H[i] << " ";
		//cout << "\n";

		for (int i = 1; i <= N; ++i)
		{
			TA[i] = H[i]/A;
			if (H[i] % A) TA[i]++;
			SA[i] = SA[i-1] + TA[i];

			TB[i] = H[i]/B;
			if (H[i] % B) TB[i]++;
			SB[i] = SB[i-1] + TB[i];
		}
		//for (int i = 0; i < N; ++i) cout << SA[i] << " ";
		//cout << "\n";

		//for (int i = 0; i < N; ++i) cout << SB[i] << " ";
		//cout << "\n";

		// Assume A and B attack m monsters together, then binary search for smallest time
		int t_min = N;
		for (int m = 0; m <= N; ++m)
		{
			int t_start = 0;
			int t_end = N; // discard solutions where it takes more than N individual steps
			while (t_start < t_end)
			{
				int t_mid = (t_start + t_end)/2;
				
				if (possible(t_mid, m, N)) t_end = t_mid;
				else t_start = t_mid + 1;
			}
			if (possible(t_end, m, N)) t_min = min(t_min, t_end + m);
			else if (possible(t_start, m, N)) t_min = min(t_min, t_start + m);
			
		}
		cout << t_min << "\n";
	}
	return 0;
}