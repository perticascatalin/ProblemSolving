#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define NM 2005
#define LL long long

// Graph related variables
vector< pair<int,int> > G[NM];
int adj[NM][NM], pos[NM][NM];
int vis[NM], pre[NM], chain[NM];

// Tree related variables
vector < pair<int,int> > ARB[NM];
int up[NM];
LL sum_chain[NM][4], num_chain[NM][4];

int N, Q;

void find_chain(int start, int stop)
{
	memset(vis, 0, sizeof(vis));
	memset(chain, 0, sizeof(chain));
	queue <int> enq;

	enq.push(start);
	vis[start] = 1;
	while (!enq.empty())
	{
		int node = enq.front();
		enq.pop();
		if (node == stop)
		{
			chain[stop] = 1;
			while(node != start)
			{
				node = pre[node];
				chain[node] = 1;
			}
		}
		else
		{
			for (int i = 0; i < G[node].size(); ++i)
			{
				int nnode = G[node][i].first;
				if (!vis[nnode])
				{
					enq.push(nnode);
					vis[nnode] = 1;
					pre[nnode] = node;
				}
			}
		}
	}
}

void create_tree()
{
	for (int i = 0; i <= N; ++i) ARB[i].clear();
	memset(up, -1, sizeof(up));
	memset(vis, 0, sizeof(vis));
	queue <int> enq;

	for (int i = 0; i <= N; ++i)
		if (chain[i])
		{
			enq.push(i);
			vis[i] = 1;
		}

	while (!enq.empty())
	{
		int node = enq.front();
		enq.pop();
		for (int i = 0; i < G[node].size(); ++i)
		{
			int nnode = G[node][i].first;
			int cost = G[node][i].second;
			if (!vis[nnode])
			{
				int act_node = node;
				if (chain[node]) act_node = 0;
				ARB[act_node].push_back(make_pair(nnode, cost) );
				enq.push(nnode);
				vis[nnode] = 1;
				up[nnode] = act_node;
			}
		}
	}
}

int compute_dp(int root)
{
	if (ARB[root].empty())
	{
		num_chain[root][1] = 1;
		sum_chain[root][1] = 0;
		num_chain[root][2] = 0;
		sum_chain[root][2] = 0;
		num_chain[root][3] = 0;
		sum_chain[root][3] = 0;
		num_chain[root][0] = 1;
		sum_chain[root][0] = 0;
	}
	else
	{
		for (int i = 0; i < ARB[root].size(); ++i)
		{
			int node = ARB[root][i].first;
			compute_dp(node);
		}
		// Straight down chains
		num_chain[root][1] = 1;
		sum_chain[root][1] = 0;
		for (int i = 0; i < ARB[root].size(); ++i)
		{
			int node = ARB[root][i].first;
			int cost = ARB[root][i].second;
			num_chain[root][1] += num_chain[node][1];
			sum_chain[root][1] += ((LL)cost * num_chain[node][1] + sum_chain[node][1]);
		}

		// Umbrella chains
		num_chain[root][2] = 0;
		sum_chain[root][2] = 0;
		if (ARB[root].size() > 1)
		{
			for (int i = 0; i < ARB[root].size(); ++i)
				for (int j = i + 1; j < ARB[root].size(); ++j)
				{
					int node1 = ARB[root][i].first;
					int cost1 = ARB[root][i].second;
					int node2 = ARB[root][j].first;
					int cost2 = ARB[root][j].second;

					// Tricky stuff
					num_chain[root][2] += num_chain[node1][1] * num_chain[node2][1];

					sum_chain[root][2] += num_chain[node1][1] * sum_chain[node2][1];
					sum_chain[root][2] += num_chain[node2][1] * sum_chain[node1][1];
					sum_chain[root][2] += num_chain[node1][1] * num_chain[node2][1] * (LL)(cost1 + cost2);
				}
		}

		// Below chains
		num_chain[root][3] = 0;
		sum_chain[root][3] = 0;
		for (int i = 0; i < ARB[root].size(); ++i)
		{
			int node = ARB[root][i].first;
			num_chain[root][3] += num_chain[node][0];
			sum_chain[root][3] += sum_chain[node][0]; 
		}
		
		// Whole 
		num_chain[root][0] = 0;
		sum_chain[root][0] = 0;
		for (int k = 1; k <= 3; ++k)
		{
			num_chain[root][0] += num_chain[root][k];
			sum_chain[root][0] += sum_chain[root][k];
		}
	}
	return 0;
}

void print_graph()
{
	for (int i = 1; i <= N; ++i)
	{
		cout << i << " node: ";
		for (int j = 0; j < G[i].size(); ++j)
			cout << G[i][j].first << ", " << G[i][j].second << "; ";
		cout << "\n";
	}
}

void print_tree()
{
	for (int i = 0; i <= N; ++i)
	{
		if (chain[i]) continue;
		cout << i << " node: ";
		for (int j = 0; j < ARB[i].size(); ++j)
			cout << ARB[i][j].first << ", " << ARB[i][j].second << "; ";
		cout << "\n";
	}
}

int main()
{
	memset(adj, -1, sizeof(adj));
	memset(pos, -1, sizeof(pos));

	freopen ("zelda.in", "r", stdin);
	freopen ("zelda.out", "w", stdout);

	scanf("%d\n", &N);

	for (int i = 1; i < N; ++i)
	{
		int a, b, c;
		scanf("%d %d %d\n", &a, &b, &c);
		int pos_a = G[a].size();
		int pos_b = G[b].size();
		pos[a][b] = pos_a;
		pos[b][a] = pos_b;
		adj[a][b] = c;
		adj[b][a] = c;
		G[a].push_back(make_pair(b,c));
		G[b].push_back(make_pair(a,c));
	}
	// print_graph();

	scanf("%d\n", &Q);
	for (int i = 1; i <= Q; ++i)
	{
		int q, a, b, c;
		scanf("%d", &q);
		if (q == 1) // query
		{
			scanf("%d %d\n", &a, &b);
			// do stuff
			find_chain(a,b);
			// for (int i = 1; i <= N; ++i) if (chain[i]) cout << i << "\n";
			create_tree();
			// print_tree();
			// printf("\n");
			compute_dp(0);
			printf("%lld\n", sum_chain[0][0]);
		}
		else // update
		{
			scanf("%d %d %d\n", &a, &b, &c);
			int pos_a = pos[a][b];
			int pos_b = pos[b][a];
			G[a][pos_a] = make_pair(b, c);
			G[b][pos_b] = make_pair(a, c);
			adj[a][b] = c;
			adj[b][a] = c;
			// print_graph();
		}
	}

	return 0;
}