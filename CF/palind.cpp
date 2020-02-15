#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

#define NM 105

int pal[NM][NM];
int pos[NM];
int is_pal[NM];
int used[NM];
vector <string> words;
list <int> front;
list <int> back;
int middle;

int main()
{
	// ifstream cin("palind.in");
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;
		words.push_back(str);
	}

	memset(pal, 0, sizeof(pal));
	memset(pos, 0, sizeof(pos));
	memset(is_pal, 0, sizeof(is_pal));
	memset(used, 0, sizeof(used));
	middle = -1;

	for (int i = 0; i < N; ++i)
	{
		string a = words[i].c_str();
		string c = words[i].c_str();
		reverse(c.begin(), c.end());
		for (int j = i + 1; j < N; ++j)
		{
			string b = words[j].c_str();
			if (c.compare(b) == 0)
			{
				pal[i][j] = 1;
				pal[j][i] = 1;
				pos[i] = j;
				pos[j] = i;
			}
		}
		if (c.compare(a) == 0) is_pal[i] = 1;
	}	

	for (int i = 0; i < N; ++i)
	{
		if (used[i]) continue;
		if (pos[i])
		{
			front.push_back(i);
			back.push_front(pos[i]);
			used[i] = 1;
			used[pos[i]] = 1;
		}
		if (is_pal[i] && !used[i])
		{
			middle = i;
			used[i] = 1;
		}

	}

	int l = 2 * front.size() * M;
	if (middle != -1) l += M;
	cout << l << endl;

	string final_str = "";
	for (list<int>::iterator it = front.begin(); it != front.end(); ++it)
	{
		final_str += words[*it];
	}
	if (middle != -1) final_str += words[middle];
	for (list<int>::iterator it = back.begin(); it != back.end(); ++it)
	{
		final_str += words[*it];
	}
	cout << final_str << endl;

	// for (int i = 0; i < N; ++i) cout << words[i] << endl;

	// for (int i = 0; i < N; ++i)
	// {
	// 	for (int j = 0; j < N; ++j) cout << pal[i][j] << " ";
	// 	cout << endl;
	// }	

	// cout << endl;
	// for (int i = 0; i < N; ++i) cout << is_pal[i] << " "; cout << endl;

	return 0;
}