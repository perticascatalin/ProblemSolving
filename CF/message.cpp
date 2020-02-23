#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

#define LL long long

LL num[100005][26];
LL sol[26][26];

int main()
{
	// ifstream cin("message.in");
	string S; cin >> S;
	int n = S.size();
	memset(num, 0, sizeof(num));
	memset(sol, 0, sizeof(sol));
	num[0][S[0]-'a'] = 1;
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < 26; ++j)
		{
			num[i][j] = num[i-1][j];
			if (j + 'a' == S[i]) num[i][j]++;
		}

	for (int i = 1; i < n; ++i)
		for (int j = 0; j < 26; ++j)
			sol[j][S[i]-'a'] += num[i-1][j];

	LL maxi = 0;
	for (int j = 0; j < 26; ++j) maxi = max(maxi, num[n-1][j]);
	for (int i = 0; i < 26; ++i)
		for (int j = 0; j < 26; ++j)
			maxi = max(maxi, sol[i][j]);
	cout << maxi << endl;
	return 0;
}