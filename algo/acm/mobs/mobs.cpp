#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

#define NMAX 100005

int main()
{
	int TA[NMAX], TB[NMAX];
	long long SA[NMAX], SB[NMAX];

	ifstream cin ("mobs.in");
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

		// Assume A and B can attack up to s seconds by themseleves, then attack together
		int t_min = N;
		for (int s = 0; s <= N; ++s)
		{
			int left = 0;
			int right = N;
			while (left < right - 1)
			{
				int mid = (left + right) / 2;
				long long req_s = SA[mid];
				if (req_s <= s) left = mid;
				else right = mid - 1;
			}
			int kills_A = left;
			if (SA[right] <= s) kills_A = right;

			left = 0;
			right = N - kills_A;
			while (left < right - 1)
			{
				int mid = (left + right) / 2;
				long long req_s = SB[mid + kills_A] - SB[kills_A];
				if (req_s <= s) left = mid;
				else right = mid - 1;
			}
			int kills_B = left;
			if (SB[right + kills_A] - SB[kills_A] <= s) kills_B = right;
			//cout << "kills A = " << kills_A << " kills B = " <<  kills_B << "\n";

			int index_A_B = kills_A + kills_B + 1;
			int total_time = s + N - index_A_B + 1;
			if (total_time < t_min)
			{
				t_min = total_time;
				cout << s << " " << kills_A << " " << kills_B << " " << N - kills_A - kills_B << "\n";
			}
		}
		cout << t_min << "\n";
	}
	return 0;
}