#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;

int main()
{
	// ifstream cin("assign.in");
	cin >> T;
	while(T--)
	{
		cin >> N;
		vector <int> a;
		for (int i = 0; i < 2*N; ++i)
		{
			int num; cin >> num;
			a.push_back(num);
		}
		sort(a.begin(), a.end());
		// for (int i = 0; i < 2*N; ++i)
		// 	cout << a[i] << " ";
		// cout << endl;
		cout << a[N]-a[N-1] << endl;
	}
	return 0;
}