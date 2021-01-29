#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	//ifstream cin ("qualprel.in");
	//ofstream cout ("qualprel.out");

	int T; cin >> T;
	while (T--)
	{
		int N, K; cin >> N >> K;
		vector <int> scores;
		for (int i = 0; i < N; ++i)
		{
			int score; cin >> score;
			scores.push_back(-score);
		}
		sort(scores.begin(), scores.end());
		int last = K - 1;
		while (last < N - 1 && scores[last] == scores[last + 1]) last++;
		cout << last + 1 << "\n";
	}

	return 0;
}