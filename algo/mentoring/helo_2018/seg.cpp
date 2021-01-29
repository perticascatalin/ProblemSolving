#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define NM 17
#define inf 170000
#define X1 first.first
#define Y1 first.second
#define X2 second.first
#define Y2 second.second
#define x first
#define y second
#define point pair <double, double>
#define mp make_pair

ifstream fin ("seg.in");
ofstream fout ("seg.out");

int T;
int N;
pair < point, point >  points[NM];
double dp[(1<<NM)][NM][NM][2][2];

double points[NM][4];
x1 = points[i][0];
y1 = points[i][1];

double square(double num) { return num * num; }
double distance(point p1, point p2) { return sqrt(square(p1.x - p2.x) + square(p1.y - p2.y)); }

void calc_dp()
{
	// state
	// shortest path including subset, starting (start, start_side) & ending (end, end_side)
	// option1: (1<<N), N, 2, N, 2 through N = 17 -> TC 151.519.232
	// option2: fix one segment, through N = 16 -> TC 67.108.864

	for (int sub = 0; sub < (1<<N); ++sub)
		for (int i = 0; i < N; ++i)
			for (int is = 0; is < 2; ++is)
				for (int j = 0; j < N; ++j)
					for (int js = 0; js < 2; ++js)
						dp[sub][i][j][is][js] = inf;

	for (int i = 0; i < N; ++i)
	{
		dp[(1<<i)][i][i][0][1] = /*distance(points[i].first, points[i].second)*/0.0;
		dp[(1<<i)][i][i][1][0] = /*distance(points[i].second, points[i].first)*/0.0;
	}

	for (int sub = 1; sub < (1<<N); ++sub) 
	{
		int computed = 0;
		for (int i = 0; i < N; ++i)
			if ((1<<i) == sub) computed = 1;

		if (computed) continue;

		for (int i = 0; i < N; ++i)
			if ((1<<i) & sub)
			for (int j = 0; j < N; ++j)
				if (j != i && ((1<<j) & sub))
				for (int is = 0; is < 2; ++is)
					for (int js = 0; js < 2; ++js)
						for (int k = 0; k < N; ++k)
							if (k != j && ((1<<k) & sub))
							for (int ks = 0; ks < 2; ++ks)
							{
								point a, b, c;
								if (ks) a = points[k].second;
								else a = points[k].first;

								if (js) {
									b = points[j].first;
									c = points[j].second;
								}
								else {
									b = points[j].second;
									c = points[j].first;
								}
								dp[sub][i][j][is][js] = min(dp[sub][i][j][is][js],
									dp[sub - (1<<j)][i][k][is][ks] + distance(a,b) /* + distance(b,c)*/);
							}
	}
}

void solve()
{
	fin >> T;
	while (T--)
	{
		fin >> N;
		for (int i = 0; i < N; ++i)
		{
			double x1, y1, x2, y2;
			fin >> x1 >> y1 >> x2 >> y2;
			points[i] = mp(mp(x1,y1), mp(x2,y2));
		}
		calc_dp();
		double best = inf;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				if (i != j)
				for (int is = 0; is < 2; ++is)
					for (int js = 0; js < 2; ++js)
					{
						point a, b;
						if (is) a = points[i].second;
						else a = points[i].first;

						if (js) b = points[j].second;
						else b = points[j].first;

						best = min(best, dp[(1<<N)-1][i][j][is][js] + distance(a, b));
					}

		fout << fixed << setprecision(10) << best << "\n";
	}
}

int main()
{
	solve ();
	return 0;
}