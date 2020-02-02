#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int T;
	// ifstream cin("ebne.in");
	cin >> T;
	// cout << T << endl;
	while (T--)
	{
		int n; string s;
		cin >> n;
		cin >> s;
		// cout << s << endl;

		string sol = "";
		int le = n-1; // last even
		while (le && (s[le]-'0') % 2 == 0) le--;
		// cout << le << endl;
		if ((s[le]-'0') % 2 == 0)
		{
			sol = "-1";
			cout << sol << endl;
			continue;
		}
		int sum = 0;
		for (int i = 0; i <= le; ++i)
			sum += (s[i] - '0');

		// number has even sum and last digit is uneven => good
		if (sum % 2 == 0)
		{
			sol = s.substr(0, le+1);
			cout << sol << endl;
			continue;
		}
		
		// now we have an odd sum
		// need to find an odd digit to remove, except first one
		// if we reach end, which is an odd digit, that means no solution
		// first digit skip, so we don't have leading zeros
		int ok = 0;
		int to_erase = 0;
		sol = s.substr(0, le+1);
		for (int i = 1; i < le; ++i)
			if ((s[i] - '0') % 2 == 1)
			{
				to_erase = i;
				ok = 1;
			}

		if (!ok) // no solution
		{
			sol = "-1";
			cout << sol << endl;
		}
		else // erase odd digit found and should be ok
		{
			sol.erase(to_erase, 1);
			cout << sol << endl;
		}
	}

	return 0;
}