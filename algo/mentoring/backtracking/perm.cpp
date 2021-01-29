#include <fstream>


using namespace std;

#define NMAX 10

int sol[NMAX];
int used[NMAX];

int N;

ifstream cin ("perm.in");
ofstream cout ("perm.out");

void print_perm()
{
	for (int i = 1; i <= N; ++i) cout << sol[i] << " ";
	cout << "\n";
}

void back(int pas)
{
	if (pas == N + 1) 
	{
		print_perm();
		return ;
	}
	for (int i = 1; i <= N; ++i)
	{
		if (used[i]) continue;
		sol[pas] = i;
		used[i] = 1;
		back (pas + 1);
		used[i] = 0;
	}
}

int number_perm(int n) 
{
	int c = 1;
	for (int i = 2; i <= n; i++)  c *= i;
	return c;
}

int main()
{
	int T; cin >> T;
	while (T--)
	{
		cin >> N;
		cout << number_perm(N) << "\n";
		back(1);
	}

	return 0;
}