#include <fstream>

using namespace std;

// 1<<N = 2^N
// 1 shifted N times to the left
// 1<<0 = 1 = 1
// 1<<1 = 10 = 2
// 1<<2 = 100 = 4...
// 0, 1, 2, ... 7
// 000
// 001
// 010
// 011
// 6543210 
// 1010001
//   <----

int main()
{
	ifstream cin ("subset.in");
	ofstream cout ("subset.out");

	int T; cin >> T;
	while (T--)
	{
		int N; cin >> N;
		for (int sub = 0; sub < (1<<N); sub++)
		{
			int has_ones = 0;
			for (int i = 0; i < N; ++i)
				if (sub & (1<<i)) has_ones = 1;
			if (has_ones)
			{
				for (int i = 0; i < N; ++i)
					if (sub & (1<<i)) cout << (i+1) << " ";
			}
			else
			{
				cout << "none";
			}
			cout << "\n";
		}
	}
	return 0;
}