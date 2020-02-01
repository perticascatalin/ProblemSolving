#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ABC
{
	pair<int,int> getPositions(char c1, char c2, string sol)
	{
		// compute last A and first B
		int ok = 0;
		int succ = 0;
		int first_B = 0, last_A = 0;
		int N = sol.size();
		for (int i = N-1; i >= 0; --i)
		{
			if (sol[i] == c1) {first_B = i; ok = 1;}
			if (sol[i] == c2 && ok) {last_A = i; succ = 1; break;}
		}
		if (succ) return make_pair(first_B, last_A);
		else return make_pair(-1,-1);
	}
	public:
	string createString(int N, int K)
	{
		for (int a = 0; a <= N; ++ a)
			for (int b = 0; b <= N-a; ++b)
			{
				int c = N-a-b;
				string sol = "";
				for (int i = 0; i < a; ++i)
					sol += 'A';
				for (int i = 0; i < b; ++i)
					sol += 'B';
				for (int i = 0; i < c; ++i)
					sol += 'C';
				int max_pos = b * c + a * (b+c);
				if (max_pos < K) continue;
				int ok = 1;
				while (max_pos > K && ok)
				{
					ok = 0;
					pair<int,int> pr = getPositions('B', 'C', sol);
					if (pr.first == -1) pr = getPositions('A', 'C', sol);
					if (pr.first == -1) pr = getPositions('A', 'B', sol);

					if (pr.first != -1)
					{
						char aux = sol[pr.first];
						sol[pr.first] = sol[pr.second];
						sol[pr.second] = aux;
						ok = 1;
						max_pos -= 1;
					}
				}
				if (ok && max_pos == K) return sol;
			}
		return "";
	}
};

int main()
{
	ABC run;
	cout << run.createString(3, 3) << endl;
	cout << run.createString(3, 0) << endl;
	cout << run.createString(5, 10) << endl;
	cout << run.createString(15, 36) << endl;
	return 0;
}