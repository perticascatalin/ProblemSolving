#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// ifstream cin("mezo.in");
	int N; cin >> N;
	string S; cin >> S;
	int count_L = 0; int count_R = 0;
	for (int i = 0; i < N; ++i)
		if (S[i] == 'L') ++count_L;
		else ++count_R;
	cout << count_L + count_R + 1 << endl;

	return 0;
}