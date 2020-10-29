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
	for (int k = 0; k < 8; ++k)
	{
		int nl = l + pl[k];
		int nc = c + pc[k];
		if (nl < 0 || nl >= N) continue;
		if (nc < 0 || nc >= N) continue;
		if (mark[nl][nc]) continue;

		mark[nl][nc] = 1;
		sol.push_back(N * nl + nc);
		explore(step + 1);
		sol.pop_back();
		mark[nl][nc] = 0;
		if (found) return;
	}
}

int main()
{
	int l, c;
	ifstream cin("k.in");
	ofstream cout("k.out");
	cin >> N >> l >> c;
	clock_t begin = clock();
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