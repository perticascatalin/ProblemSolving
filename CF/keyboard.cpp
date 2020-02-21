#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
	// first you need to have exactly n-1 edges (ensure no cycles)
	// otherwise you have to pass through same letter more than once
	// meaning that they can't be arranged in a row

	// then you want them to be a chain

	// enumerate by walking the chain

	// then place remaining letters

	// ifstream cin("keyboard.in");
	int T; cin >> T;
	while(T--)
	{
		string S; cin >> S;
		vector <int> G[26];
		int A[26][26];
		int used[26];
		memset(A, 0, sizeof(A));
		memset(used, 0, sizeof(used));
		int n = S.size();
		for (int i = 0; i < n - 1; ++i)
		{
			int a = S[i] - 'a';
			int b = S[i+1] - 'a';
			G[a].push_back(b);
			G[b].push_back(a);
			A[a][b] = 1;
			A[b][a] = 1;
			used[a] = 1;
		}
		used[S[n-1]-'a'] = 1;

		int n_edges = 0;
		for (int i = 0; i < 26; ++i)
			for (int j = i + 1; j < 26; ++j)
				if (A[i][j]) ++n_edges;

		int n_used = 0;
		for (int i = 0; i < 26; ++i) if(used[i]) ++n_used;

		// cout << "n edges " << n_edges << endl;
		// cout << "n used " << n_used << endl;

		if (n_edges != n_used - 1)
		{
			cout << "NO" << endl;
			continue;
		}
		else
		{
			// just one node
			if (n_used == 1)
			{
				cout << "YES" << endl;
				string sol = "";
				for (int i = 0; i < 26; ++i) sol += (i + 'a');
				cout << sol << endl;
				continue;
			}
			// you need to make sure that exactly 2 nodes have out_degree 1
			// the rest 2
			else
			{
				int deg[26];
				memset(deg, 0, sizeof(deg));
				for (int i = 0; i < 26; ++i)
					for (int j = 0; j < 26; ++j)
						if (A[i][j]) deg[i]++;

				int s_node;
				int n_od1 = 0; int n_od2 = 0;
				for (int i = 0; i < 26; ++i)
				{
					if (deg[i] == 1) ++n_od1;
					if (deg[i] == 2) ++n_od2;
					if (deg[i] == 1) s_node = i;
				}
				if (n_od1 != 2 || n_od2 != (n_used - 2))
				{
					cout << "NO" << endl;
					continue;
				}
				else
				{
					int can = 0;
					int walked[26];
					string sol = "";
					memset(walked, 0, sizeof(walked));
					do
					{
						can = 0;
						sol += (s_node + 'a');
						walked[s_node] = 1;
						for (int i = 0; i < G[s_node].size(); ++i)
							if (!walked[G[s_node][i]])
							{
								can = 1;
								s_node = G[s_node][i];
								break;
							}
					}
					while(can);
					for (int i = 0; i < 26; ++i) if (!used[i]) sol += (i + 'a');
					cout << "YES" << endl;
					cout << sol << endl;
					continue;
				}
			}
		}
	}
	return 0;
}