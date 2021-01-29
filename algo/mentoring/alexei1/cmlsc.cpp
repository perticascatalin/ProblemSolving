#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define NM 1024

int A[NM], B[NM];
int cmlsc[NM][NM];
int wh[NM][NM];

void update(int i, int j, int cur, int dir)
{
	if (cur >= cmlsc[i][j])
	{
		cmlsc[i][j] = cur;
		wh[i][j] = dir;
	}
}

int main()
{
	ifstream cin("cmlsc.in");
	ofstream cout("cmlsc.out");

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) cin >> A[i];
	for (int i = 1; i <= M; ++i) cin >> B[i];

	memset(cmlsc, 0, sizeof(cmlsc));

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
		{
			int cur = cmlsc[i][j];
			if (A[i] == B[j])
			{
				cur = cmlsc[i-1][j-1] + 1;
				update(i, j, cur, 0);
			}
			cur = cmlsc[i-1][j];
			update (i, j, cur, 1);

			cur = cmlsc[i][j-1];
			update (i, j, cur, 2);
		}

	cout << cmlsc[N][M] << "\n";

	int i = N; int j = M;
	vector <int> solution;
	while (i && j)
	{
		if (wh[i][j] == 0)
		{
			solution.push_back(A[i]);
			--i;
			--j;
		}
		else if (wh[i][j] == 1)
		{
			--i;
		}
		else if (wh[i][j] == 2)
		{
			--j;
		}
	}

	reverse(solution.begin(), solution.end());
	for (int i = 0; i < solution.size(); ++i) cout << solution[i] << " "; 

	return 0;
}