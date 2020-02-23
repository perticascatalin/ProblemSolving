#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	// ifstream cin("food.in");
	int T; cin >> T;
	while(T--)
	{
		int S; cin >> S;
		int ok = 1;
		int sol = 0;
		while (S && ok)
		{
			ok = 0;
			for (int i = 1000000000; i >= 10; i /= 10)
				if (S >= i)
				{
					S -= i;
					S += (i/10);
					sol += i;
					ok = 1;
					break;
				}
		}
		sol += S;
		cout << sol << endl;
	}

	return 0;
}