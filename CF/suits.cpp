#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// ifstream cin("suits.in");

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	int max_sum = 0;
	for (int i = 0; i <= a; ++i)
	{
		int t_out = min(min(a,i),min(d,i));
		int s_out = min(min(b,c),d-t_out);
		int c_sum = t_out * e + s_out * f;
		max_sum = max(max_sum, c_sum);
	}
	cout << max_sum << endl;

	return 0;
}