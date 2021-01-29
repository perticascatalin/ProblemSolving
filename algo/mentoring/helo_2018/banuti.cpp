#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define SM 5005
#define NM 50005
#define inf 1000000000

ifstream fin ("banuti.in");
ofstream fout ("banuti.out");

int N; int B[NM]; int minB[SM];
int bmin, cost[SM];
vector <pair<int, int> > G[SM];
queue <int> Q;
int isin[SM];
int viz[SM];

int main()
{
	fin >> N;
	for (int i = 0; i < N; ++i)
	{
		fin >> B[i];
	}

	bmin = inf;
	for (int i = 0; i < N; ++i)
	{
		bmin = min (bmin, B[i]);
	}

	for (int i = 0; i < bmin; ++i)
	{
		cost[i] = inf;
		minB[i] = inf;
	}

	for (int i = 0; i < N; ++i)
		minB[B[i] % bmin] = min(minB[B[i] % bmin], B[i]);

	for (int i = 0; i < bmin; ++i)
		if (minB[i] < inf)
		{
			for (int j = 0; j < bmin; ++j)
				G[j].push_back(make_pair((j + i)%bmin, minB[i]));
		}

	memset(viz, 0, sizeof(viz));
	memset(isin, 0, sizeof(isin));

	/*
	for (int i = 0; i < bmin; ++i)
	{
		cout << minB[i] << " ";
	}
	*/

	for (int i = 0; i < bmin; ++i)
		if (minB[i] < inf)
		{
			cost[i] = minB[i];
			Q.push(i);
			isin[i] = 1;
			viz[i] = 1;
		}

	while (!Q.empty())
	{
		int nod = Q.front();
		Q.pop();
		isin[nod] = 0;
		
		for (int i = 0; i < G[nod].size(); ++i)
		{
			int nnod = G[nod][i].first;
			int adcost = G[nod][i].second;
			
			if (cost[nod] + adcost < cost[nnod])
			{
				cost[nnod] = cost[nod] + adcost;
				if (!isin[nnod])
				{
					Q.push(nnod);
					isin[nnod] = 1;
					viz[nnod] = 1;
				}	
			}	
		}	
	}

	int ok = 1;
	for (int i = 0; i < bmin; ++i)
		if (!viz[i]) ok = 0;

	if (!ok) fout << "-1";
	else
	{
		int smin = 0;
		for (int i = 0; i < bmin; ++i)
			smin = max(smin, cost[i] - bmin);
		fout << smin;
	}

	return 0;
}