#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

#define NM 10

int N;
int mark[NM][NM];
int pl[8] = {-1,-2,-2,-1,1,2,2,1};
int pc[8] = {-2,-1,1,2,2,1,-1,-2};
int found;
vector <int> sol;
vector <int> G[NM*NM];

void explore(int step)
{
	if (step == N * N)
	{
		// We have a solution
		// Need to print it & return
		found = 1;
		for (int i = 0; i < sol.size(); ++i)
		{
			int l = sol[i] / N;
			int c = sol[i] % N;
			cout << l << " " << c << "\n";
		}
	}
	int loc = sol[step - 1];
	int l = loc / N;
	int c = loc % N;
	for (int k = 0; k < G[loc].size(); ++k)
	{
		int nloc = G[loc][k];
		int nl = nloc / N;
		int nc = nloc % N;
		if (mark[nl][nc]) continue;

		mark[nl][nc] = 1;
		sol.push_back(nloc);
		explore(step + 1);
		sol.pop_back();
		mark[nl][nc] = 0;
		if (found) return;
	}
}

void build_graph()
{
	for (int loc = 0; loc < N * N; ++loc)
	{
		int l = loc / N;
		int c = loc % N;
		for (int k = 0; k < 8; ++k)
		{
			int nl = l + pl[k];
			int nc = c + pc[k];
			if (nl < 0 || nl >= N) continue;
			if (nc < 0 || nc >= N) continue;
			int nloc = N * nl + nc;
			G[loc].push_back(nloc);
		}
	}
}

int main()
{
	int l, c;
	ifstream cin("k.in");
	ofstream cout("k.out");
	cin >> N >> l >> c;
	clock_t begin = clock();
	build_graph();
	memset(mark, 0, sizeof(mark));
	mark[l][c] = 1;
	sol.push_back(N * l + c);
	found = 0;
	explore(1);
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << elapsed_secs << "\n";
	cout << found << "\n";
	return 0;
}