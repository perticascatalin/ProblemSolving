#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int funk(int x, int y)
{
	return (x | y) - y;
}

int main()
{
	// ifstream cin("anu.in");
	
	cin >> N;
	vector <pair<int, int> > a;
	for (int i = 0; i < N; ++i)
	{
		int num; cin >> num;
		int bc = 0;
		for (int j = 0; j < 31; ++j)
			if (num & (1<<j)) ++bc;
		a.push_back(make_pair(-bc, num));
	}
	sort(a.begin(), a.end());

	int i = 0;
	int j = N-1;

	while(i <= j)
	{
		cout << a[i].second << " ";
		if (i != j) cout << a[j].second << " ";
		++i;
		--j;
	}
	cout << endl;

	// for (int i = 0; i < N; ++i)
	// 	cout << a[i].second << " ";
	// cout << endl;

	// for (int i = 0; i <= 11; ++i)
	// {
	// 	for (int j = 0; j <= 11; ++j)
	// 		cout << i << " | " << j << ": " << funk(i,j) << endl;
	// 	cout << endl;
	// }

	return 0;
}