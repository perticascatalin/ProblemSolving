//  ( ( () ) () )
//0 1 2 32 1 21 0
// [1 x 0 up]
// 1 x 0 down
// 1 x 1 up
// 2 x 1 down
// 2 x 2 up
// 1 x 2 down

// N x L   down
// N x L+1 up

// ()() -> () | () -> 2,2
// ((())()) -> (())(()) -> 4,4
// 

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int correct_par(string par)
{
	int count = 0;
	for (int i = 0; i < par.size(); ++i)
	{
		if (par[i] == '(') count++;
		else count--;

		if (count < 0) return 0;
	}
	if (count == 0) return 1;
	else return 0;
}

pair <vector<int>, vector <int> > split_par(string par)
{
	int count = 0;
	vector <int> pos_count;
	vector <int> par1, par2;
	stack <int> last_pos;
	vector <int> assig;
	int to_par1 = 0; int to_par2 = 0;

	pos_count.push_back(0);
	for (int i = 0; i < par.size(); ++i)
	{
		if (par[i] == '(') 
		{
			count++;
			if (to_par1 < to_par2)
			{
				par1.push_back(i+1);
				assig.push_back(1);
				++to_par1;
			}
			else
			{
				par2.push_back(i+1);
				assig.push_back(2);
				++to_par2;
			}
			last_pos.push(i);
		}
		else
		{
			int pos = last_pos.top();
			int who = assig[pos];
			if (who == 1)
			{
				par1.push_back(i+1);
				assig.push_back(1);
			}
			else
			{
				par2.push_back(i+1);
				assig.push_back(2);
			}

			last_pos.pop();
			count--;
		}
		pos_count.push_back(count);
	}

	return make_pair(par1, par2);
}

int main()
{
	ifstream cin ("brackets.in");
	ofstream cout ("brackets.out");

	int T;
	cin >> T;
	while (T--)
	{
		int N; string par;
		cin >> N;
		cin >> par;

		//cout << N << " " << par << "\n";
		if (!correct_par(par)) cout << "-1\n";
		else
		{
			//cout << "smth\n";
			pair <vector<int>, vector<int> > sol = split_par(par);
			cout << sol.first.size() << "\n";
			for (int i = 0; i < sol.first.size(); ++i) cout << sol.first[i] << " ";
			cout << "\n";
			cout << sol.second.size() << "\n";
			for (int i = 0; i < sol.second.size(); ++i) cout << sol.second[i] << " ";
			cout << "\n";
		}
	}

	return 0;
}