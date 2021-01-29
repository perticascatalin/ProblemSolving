#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	//ifstream cin ("spread2.in");
	//ofstream cout ("spread2.out");

	int T; cin >> T;
	while (T--)
	{
		int N; cin >> N;
		vector <int> A;
		for (int i = 0; i < N; ++i)
		{
			int a; cin >> a;
			A.push_back(a);
		}
		int last = 0;
		int avail = A[last];
		int days = 1;
		while (last < N)
		{
			int new_avail = avail;
			while (last < N - 1 && avail)
			{
				last += 1;
				new_avail += A[last];
				avail--;
			}
			if (last == N - 1) break;
			days++;
			avail = new_avail;
		}
		cout << days << "\n";
	}

	return 0;
}