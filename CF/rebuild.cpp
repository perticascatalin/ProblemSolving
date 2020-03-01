#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define NM 200005

vector<int> G[NM], GT[NM];
int D[NM], used[NM], Q[NM], road[NM];

int main()
{
	// ifstream cin("rebuild.in");
	int N, M; cin >> N >> M;
	for (int i = 1; i <= M; ++i)
	{
		int a,b; cin >> a >> b;
		GT[b].push_back(a);
		G[a].push_back(b);
	}

	memset(used, 0, sizeof(used));

	int K; cin >> K;
	for (int i = 1; i <= K; ++i) cin >> road[i];
	int t = road[K];

	int first = 0;
	int last = 0;
	Q[last] = t;
	used[t] = 1;
	D[t] = 0;
	while (first <= last)
	{
		int node = Q[first];
		++first;
		for (int i = 0; i < GT[node].size(); ++i)
		{
			int nnode = GT[node][i];
			if (used[nnode]) continue;
			++last;
			Q[last] = nnode;
			used[nnode] = 1;
			D[nnode] = D[node] + 1;
		}
	}

	int overall = 0;
	int add = 0;
	for (int i = 2; i < K; ++i)
	{
		int cur = road[i];
		int prev = road[i-1];
		if (D[cur] != D[prev] - 1) ++overall;
		else
		{
			int exists = 0;
			for (int j = 0; j < G[prev].size(); ++j)
			{
				int nnode = G[prev][j];
				if (nnode != cur && D[nnode] == D[cur]) exists = 1;
			}
			if (exists) ++add;
		}
	}

	cout << overall << " " << overall + add << endl;

	return 0;
}