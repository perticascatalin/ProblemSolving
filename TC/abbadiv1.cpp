#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ABBADiv1
{
	public:
	string canObtain(string initial, string target)
	{
		int n = target.size();
		int bs = 0;
		for (int i = 0; i < n; ++i) if (target[i] == 'B') ++bs;
		for (int i = 0; i < n; ++i) if (initial[i] == 'B') --bs;
		// cout << bs << "\n";

		string final = target;
		int ok = 1;
		while (ok)
		{
			ok = 0;
			if (initial.compare(final) == 0)
			{
				ok = 1;
				cout << "Stoppped" << "\n";
				break;
			}

			string rev = initial;
			n = final.size();
			if (bs % 2) reverse(rev.begin(), rev.end());

			// try removing the A
			string partial = final;
			if (final[n-1] == 'A')
			{
				if (partial.erase(n-1,n).find(rev) != std::string::npos)
				{
					final = partial;
					ok = 1;
					cout << "Erased A" << "\n";
					cout << "Final: " << final << "\n";
					continue;
				}
			}

			// try removing the B
			partial = final;
			if (final[0] == 'B')
			{
				if (partial.erase(0,1).find(rev) != std::string::npos)
				{
					final = partial;
					reverse(final.begin(), final.end());
					ok = 1;
					bs -= 1;
					cout << "Erased B" << "\n";
					cout << "Final: " << final << "\n";
					continue;
				}
			}
		}

		if (ok) return "Possible";
		else return "Impossible";
	}
};

int main()
{
	ABBADiv1 run;
	// cout << run.canObtain("BAAAAABAA", "BAABAAAAAB") << "\n";
	// cout << run.canObtain("A", "ABBA") << "\n";
	// cout << run.canObtain("A", "BABA") << "\n";
	// cout << run.canObtain("AAABBAABB", "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB") << "\n";
	return 0;
}