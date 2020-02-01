#include <iostream>
#include <vector>
#include <string>

using namespace std;

class AB
{
	public:
	string createString(int N, int K)
	{
		int max_pos = (N/2) * (N - N/2);
		if (K > max_pos) return "";
		string sol = "";
		for (int i = 0; i < N/2; ++i) sol += 'A';
		for (int i = N/2; i < N; ++i) sol += 'B';
		int last_A = N/2 - 1;
		int first_B = N/2;

		while(max_pos > K)
		{
			char aux = sol[last_A];
			sol[last_A] = sol[first_B];
			sol[first_B] = aux;
			max_pos -= 1;

			// recompute last A and first B
			int ok = 0;
			for (int i = N-1; i >= 0; --i)
			{
				if (sol[i] == 'B') {first_B = i; ok = 1;}
				if (sol[i] == 'A' && ok) {last_A = i; break;}
			}
		}

		return sol;
	}
};

int main()
{
	AB run;
	cout << run.createString(2, 0) << endl;
	cout << run.createString(5, 8) << endl;
	cout << run.createString(10, 12) << endl;
	return 0;
}