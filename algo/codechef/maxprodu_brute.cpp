#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#define LL long long
#define NM 505

int best[NM][NM], viz[NM][NM];
LL best_div[NM][NM];

int main()
{
	ifstream cin ("maxprodu.in");
	ofstream cout ("maxprodu.out");

	memset (best, -1, sizeof(best));
	memset (viz, 0, sizeof(viz));

	best[0][0] = 1; 
	for (int k = 1; k <= 500; ++k) // last x
		for (int i = 0; i <= 500; ++i) // N (sum)
			for (int j = 1; j <= i; ++j) // K (how many)
				if (best[i][j] != -1 && viz[i][j] != k) {}
				// need distinct x from previous 
				// finish this up sometime

	int T; cin >> T;
	while (T--)
	{
		int N, K;
		cin >> N >> K;
	}

	return 0;
}