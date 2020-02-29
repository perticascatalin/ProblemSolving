#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define target first.first
#define len first.second
#define pos second

vector <int> solution(string S, char t)
{
	vector <int> sol;
	vector <pair<pair<int,int>, int> > seq;
	int N = S.size();
	int i = 0;
	while (i < N)
	{
		int j = i + 1;
		while (j < N && S[j] == S[i]) ++j;
		j -= 1;
		seq.push_back(make_pair(make_pair(S[i] == t, j - i + 1), i));
		i = j + 1;
	}
	string C = S;
	// need to rethink this
	// for (int i = 0; i < seq.size();)
	// 	if (seq[i].target && seq[i].len % 2)
	// 	{
	// 		for (int j = i+1; j < seq.size(); ++j)
	// 		{
	// 			if (seq[j].target && seq[j].len % 2) break;
	// 			for (int k = 0; k < )
	// 			{
	// 				sol.push_back(seq[j].pos + k);
	// 			}
	// 		}
	// 	}
	// 	else ++i;
	return sol;
}

int main()
{
	ifstream cin("blocks.in");
	int N; cin >> N;
	string S, C; cin >> S;
	string tl = "WB";
	int count[2]; count[0] = count[1] = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < 2; ++j)
			if (S[i] == tl[j]) ++count[j];

	cout << count[0] << " " << count[1] << endl;
	if (count[0] % 2 == 0 || count[1] % 2 == 0)
	{
		if (count[0] % 2 == 0)
		{
			// try inverting W blocks
			vector <int> sol = solution(S, 'W');
		}
		if (count[1] % 2 == 0)
		{
			// try inverting B blocks
			vector <int> sol = solution(S, 'B');
		}
	}
	else cout << -1 << endl;

	return 0;
}