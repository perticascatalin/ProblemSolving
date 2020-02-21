#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	// ifstream cin("erase.in");
	int T; cin >> T;
	while(T--)
	{
		string S; cin >> S;
		int n = S.size();
		int i = 0;
		int sol = 0;
		while (i < n)
		{
			int j = i + 1;
			while (j < n)
			{
				if (S[j] == '1') break;
				++j;
			}
			if (j < n && S[i] == '1') sol += (j - i - 1);
			i = j;
		}
		cout << sol << endl;
	}
	return 0;
}