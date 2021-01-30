#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream cout ("mobs_gen.in");

	int T = 120;
	cout << T << "\n";

	while (T--)
	{
		int N = rand() % 99999 + 1;
		int A = rand() % 999 + 1;
		int B = rand() % 999 + 1;
		cout << N << " " << A << " " << B << "\n";
		for (int i = 0; i < N; ++i)
			cout << rand() % 999 + 1 << " ";
		cout << "\n";
	}

	return 0;
}