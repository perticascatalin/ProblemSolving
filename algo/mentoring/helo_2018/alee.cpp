#include <fstream>
#include <queue>

using namespace std;

#define NMAX 180

ifstream cin ("alee.in");
ofstream cout ("alee.out");

int p_lin[4] = {-1, 0, 1, 0};
int p_col[4] = {0, 1, 0, -1};

int N, M;
int A[NMAX][NMAX], D[NMAX][NMAX];
int l_start, l_end, c_start, c_end;
queue <pair <int, int> > Q;

void print()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
			cout << A[i][j] << " ";
		cout << "\n";
	}
}

void print1()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
			cout << D[i][j] << " ";
		cout << "\n";
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= M; ++i)
	{
		int lin, col;
		cin >> lin >> col;
		A[lin][col] = 1;

	}
	cin >> l_start >> c_start >> l_end >> c_end;

	Q.push(make_pair(l_start, c_start));
	A[l_start][c_start] = 1;
	D[l_start][c_start] = 1;
	while (!Q.empty())
	{
		pair <int, int> cell = Q.front();
		Q.pop();

		int lin = cell.first;
		int col = cell.second;
		// explore in 4 directions
		for (int k = 0; k < 4; ++k)
		{
			int n_lin = lin + p_lin[k];
			int n_col = col + p_col[k];
			if (n_lin < 1 || n_lin > N) continue;
			if (n_col < 1 || n_col > N) continue;
			if (!A[n_lin][n_col])
			{
				Q.push(make_pair(n_lin, n_col));
				A[n_lin][n_col] = 1;
				D[n_lin][n_col] = D[lin][col] + 1;
				//cout << lin << " " << col << "\n";
			}
		}
	}

	//print1();
	//cout << l_end << " " << c_end << "\n";
	cout << D[l_end][c_end];

	return 0;
}