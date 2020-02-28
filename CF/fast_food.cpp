#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int B = 3; vector <int> nums;
	for (int i = 1; i < (1<<B); ++i) nums.push_back(i);

	// ifstream cin("fast_food.in");
	int T; cin >> T;
	while (T--)
	{
		int a, b, c; cin >> a >> b >> c;
		int cc[3]; 
		int max_count = 0;
		sort(nums.begin(),nums.end());
		do {
			cc[0] = a; cc[1] = b; cc[2] = c;
			int num = 0;
			int count = 0;
			while ((cc[0] || cc[1] || cc[2]) && num < nums.size())
			{
				int ok = 1;
				for (int j = 0; j < B; ++j)
					if (nums[num] & (1<<j))
						if (!cc[j]) ok = 0;
				if (ok)
				{
					for (int j = 0; j < B; ++j)
						if (nums[num] & (1<<j)) cc[j]--;
					++count;
				}
				++num;
			}
			max_count = max(max_count, count);
		} while (next_permutation(nums.begin(), nums.end()));
		cout << max_count << endl;
	}
	return 0;
}