#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>

using namespace std;

#define cmax 100

int hand[cmax];

int same(char c1, char c2)
{
	if (hand[c1 - 'a'] == hand[c2 - 'a']) return 1;
	return 0;
}

int main()
{
	//ifstream cin ("typing.in");
	//ofstream cout ("typing.out");

	memset (hand, 0, sizeof(hand));
	hand['d' - 'a'] = 1;
	hand['f' - 'a'] = 1;
	hand['j' - 'a'] = 2;
	hand['k' - 'a'] = 2;

	int T; cin >> T;
	while (T--)
	{
		int ans = 0;
		int N; cin >> N;

		map <string, int> w_in;
		for (int w = 0; w < N; ++w)
		{
			string word; cin >> word;
			map <string, int>::iterator it = w_in.find(word);

			if(it != w_in.end())
			{
			   int val = it->second;
			   ans += val/2;
			}
			else
			{
				int val = 2;
				for (int i = 1; i < word.size(); ++i)
					if (same(word[i], word[i-1])) val += 4;
					else val += 2;
				
				w_in[word] = val;
				ans += val;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}