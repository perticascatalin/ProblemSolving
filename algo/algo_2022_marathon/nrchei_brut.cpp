#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define MAXL 5
#define SIG 21

int sol[30];
vector<string> results[31][101]; // alpha len / num pairs (n)
map <int,char> mp;

string sol_chei(int step)
{
	string res = "";
	for (int i = 1; i <= step; ++i) res = res + mp[sol[i]];
	return res;
}

string get_alpha(int pos, string res)
{
	string alpha = "";
	for (int i = pos + 1; i < res.length(); ++i) alpha = alpha + res[i];
	for (int i = 0; i < pos; ++i) alpha = alpha + res[i];
	return alpha;
}

string get_beta(int pos, string res)
{
	string beta = "";
	for (int i = pos - 1; i >= 0; --i) beta = beta + res[i];
	for (int i = res.length() - 1; i >= pos + 1; --i) beta = beta + res[i];
	return beta;
}

int compute(string res)
{
	int num_pairs = 0;
	for (int i = 0; i < res.length(); ++i)
		for (int j = i + 1; j < res.length(); ++j)
			if (sol[i+1] == sol[j+1])
			{
				string alpha_i = get_alpha(i, res);
				string beta_i = get_beta(i, res);
				string alpha_j = get_alpha(j, res);
				string beta_j = get_beta(j, res);
				if ((alpha_i == alpha_j && beta_i == beta_j) || (alpha_i == beta_j && beta_i == alpha_j)) num_pairs++;
				// string target = "aa";
				// if (res == target)
				// {
				// 	cout << "target\n";
				// 	cout << alpha_i << " " << beta_i << "\n";
				// 	cout << alpha_j << " " << beta_j << "\n";
				// }
			}
	return num_pairs;
}

int validate(int step)
{
	string res = sol_chei(step);
	int num_pairs = compute(res);
	// cout << "num pairs " << num_pairs << "\n";
	if (num_pairs <= 100) results[SIG][num_pairs].push_back(res);
	return 0;
}

int generate(int step)
{
	for (int i = 0; i < SIG; ++i)
	{
		sol[step] = i;
		validate(step);
		// if (step == MAXL) validate(step);
		if (step < MAXL) generate(step + 1);
		if (step == 1)
		{
			double completed = double(i+1)/double(SIG);
			cout << completed << " done\n";
		}
	}
	return 0;
}

int main()
{
	mp[0] = 'a'; mp[1] = 'b'; mp[2] = 'c'; mp[3] = 'd'; mp[4] = 'e'; mp[5] = 'f';
	mp[6] = 'g'; mp[7] = 'h'; mp[8] = 'i'; mp[9] = 'j'; mp[10] = 'k'; mp[11] = 'l';
	mp[12] = 'm'; mp[13] = 'n'; mp[14] = 'o'; mp[15] = 'p'; mp[16] = 'q'; mp[17] = 'r';
	mp[18] = 's'; mp[19] = 't'; mp[20] = 'u'; mp[21] = 'v'; mp[22] = 'w'; mp[23] = 'x';
	mp[24] = 'y'; mp[25] = 'z'; mp[26] = '0'; mp[27] = '1'; mp[28] = '2'; mp[29] = '3';
	generate(1);
	for (int i = 1; i <= 30; ++i)
	{
		cout << "Alpha = " << i << "\n";
		for (int j = 0; j <= 11; ++j)
		{
			cout << "For num pairs " << j << " we have " << results[i][j].size() << " solutions\n";
			// int target_sig = 2; int target_n = 1;
			// if (i == target_sig && j == target_n)
			// {
			// 	for (int k = 0; k < results[i][j].size(); ++k)
			// 		cout << results[i][j][k] << "\n";
			// }
		}
	}
	return 0;
}