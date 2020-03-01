#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// ifstream cin("adjacent.in");
	int N; cin >> N;
	string S; cin >> S;
	int sol = 0;
	for (char t = 'z'; t >= 'b'; --t)
	{
		for (int i = 0; i < S.size(); ++i)
			if (S[i] == t)
			{
				int ok = 0;
				if (i && S[i-1] == t-1) ok = 1;
				if (i+1 <= S.size() - 1 && S[i+1] == t-1) ok = 1;
				if (ok) 
				{
					S.erase(i,1);
					sol++;
					--i;
				}
			}
		for (int i = S.size() - 1; i >= 0; --i)
			if (S[i] == t)
			{
				int ok = 0;
				if (i && S[i-1] == t-1) ok = 1;
				if (i+1 <= S.size() - 1 && S[i+1] == t-1) ok = 1;
				if (ok) 
				{
					S.erase(i,1);
					sol++;
					++i;
				}
			}
	}
	cout << sol << endl;

	return 0;
}