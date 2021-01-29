#include <fstream>

using namespace std;

#define NM 260
#define inf 26000000

ifstream cin ("rf.in");
ofstream cout ("rf.out");

int N;
int cost[NM][NM], lg[NM][NM];

int main()
{
	cin >> N;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
		{
			cost[i][j] = inf;
			lg[i][j] = 0;
		}

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
		{
			cin >> cost[i][j];
			lg[i][j] = 1;
			if (i == j) lg[i][j] = 0;
		}

	for (int k = 1; k <= N; ++k)
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
			 if (i != j)
			 {
			 	int sum_cost = cost[i][k] + cost[k][j];
			 	int sum_lg = lg[i][k] + lg[k][j];
			 	if (sum_cost < cost[i][j] 
			 		|| (sum_cost == cost[i][j] && sum_lg > lg[i][j]))
			 		{
			 			cost[i][j] = sum_cost;
			 			lg[i][j] = sum_lg;
			 		}	
			 }

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
			cout << cost[i][j] << " " ;
		cout << "\n";		
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
			cout << lg[i][j] << " " ;
		cout << "\n";		
	}
	return 0;
}