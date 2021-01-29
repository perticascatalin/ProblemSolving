#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>

#define a first
#define b second

using namespace std;

int main()
{
	//ifstream cin ("chefko.in");
	//ofstream cout ("chefko.out");

	int T; cin >> T;
	while (T--)
	{
		int N, K; cin >> N >> K;
		vector <pair <int, int> > segs;
		for (int i = 0; i < N; ++i)
		{
			int A, B;
			cin >> A >> B;
			segs.push_back(make_pair(A, -B));
		}
		sort(segs.begin(), segs.end());
		priority_queue <pair<int, int> > pq;
		for (int i = 0; i < K; ++i)
			pq.push(make_pair(segs[i].b, i));

		int left = segs[K-1].a;
		int right = -pq.top().a;
		int best = 0;
		if (left <= right) best = max(best, right - left);

		for (int i = K; i < N; ++i)
		{
			pq.pop();
			pq.push(make_pair(segs[i].b, i));
			left = segs[i].a;
			right = -pq.top().a;
			if (left <= right) best = max(best, right - left);
		}
		cout << best << "\n";

	}
	return 0;
}