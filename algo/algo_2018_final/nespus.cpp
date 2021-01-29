#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define NM 100005

int N, K;
int ABC[NM][3];
vector <int> G[NM];

bool viz[NM];
int connected;

 
void parc (int nod)
{
    viz[nod] = 1;
    connected += 1;
     
    for (int i = 0; i < G[nod].size(); ++i)
    {
        int nnod = G[nod][i];
         
        if (!viz[nnod]) parc(nnod);
    }   
}

int possible(int start, int end)
{
	int result = 0;

	for (int i = start; i <= end; ++i)
	{
		int a = ABC[i][0];
		int b = ABC[i][1];
		G[a].push_back(b);
		G[b].push_back(a);
	}

	memset(viz, 0, sizeof(viz));

	for (int i = 1; i <= N; ++i) 
        if (!viz[i]) 
        {
            connected = 0;
            parc(i);
            if (connected >= K) 
            {
            	result = 1;
            	break;
            }
        }   

	for (int i = start; i <= end; ++i)
	{
		int a = ABC[i][0];
		int b = ABC[i][1];
		G[a].clear();
		G[b].clear();
	}

	return result;
}

int main()
{
	// Read the data
	freopen ("nespus.in", "r", stdin);
    freopen ("nespus.out", "w", stdout);

    scanf("%d %d", &N, &K);

    int a, b, c;
    for (int i = 1; i <= N; ++i)
    {
    	scanf("%d %d %d", &a, &b, &c);
    	ABC[i][0] = a;
    	ABC[i][1] = b;
    	ABC[i][2] = c;	
    }

    int bcur = 1000000000;

    for (int i = 1; i <= N; ++i)
    {
    	int left = i, right = N;
    	while (left < right)
    	{
    		int mid = (left + right)/2;
    		//printf ("left %d right %d mid %d\n", left, right, mid);
    		if (possible(i, mid)) right = mid;
    		else left = mid + 1;
    	}
    	//printf ("%d, %d %d\n", i, left, possible(i, left));
    	if (possible(i, left))
    	{
    		int dcur = ABC[left][2] - ABC[i][2];
    		if (dcur < bcur)
    		{
    			bcur = dcur;
    		}
    	}
    }

    printf("%d\n", bcur);

	return 0;	
}