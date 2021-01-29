#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	ofstream cout ("sieve.in");
	int T = 100000;

	cout << T << endl;

	while (T--) cout << rand() % 99998 + 2 << endl;

	return 0;
}