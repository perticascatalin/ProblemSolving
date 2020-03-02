#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// ifstream cin("angry.in");
	int T; cin >> T;
	while (T--)
	{
		int N; cin >> N;
		string S; cin >> S;
		int mom = 0; int ok = 1;
		int t = 1;
		while (ok)
		{
			ok = 0;
			vector <int> add_new;
			for (int i = 0; i < N; ++i)
				if (S[i] == 'A' && i + 1 < N && S[i+1] == 'P')
				{
					add_new.push_back(i+1);
					mom = t;
					ok = 1;
				}
			for (int i = 0; i < add_new.size(); ++i) S[add_new[i]] = 'A';
			++t;
		}
		cout << mom << endl;
	}

	return 0;
}