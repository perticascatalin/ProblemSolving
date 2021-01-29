#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream cout ("inventry_big.in");

	cout << "1\n";
	cout << "1000000\n";
	for (int i = 1; i <= 500000; ++i)
		cout << '.';
	for (int i = 500001; i <= 600000; ++i)
		cout << '#';
	for (int i = 600001; i <= 1000000; ++i)
		cout << '.';

	return 0;
}