#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	// ifstream cin("coins.in");
	int T; cin >> T;
	while(T--)
	{
		int a,b,c,n;
		cin >> a >> b >> c >> n;
		if ((a+b+c+n) % 3)
			cout << "NO" << endl;
		else
		{
			int target = (a+b+c+n) / 3;
			if (target-a >= 0 && target-b >= 0 && target-c >= 0)
				cout << "YES" << endl;
			else 
				cout << "NO" << endl;
		}
	}
	return 0;
}