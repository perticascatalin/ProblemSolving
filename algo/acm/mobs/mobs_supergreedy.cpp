#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ifstream cin("mobs.in");
	ofstream cout("mobs.out");

	int T;
	cin >> T;
	while (T--)
	{
		int N, A, B;
		vector <int> mobs_A, mobs_B, mobs_C;
		cin >> N >> A >> B;
		if (A > B) swap(A, B);
		for (int i = 0; i < N; ++i)
		{
			int h; cin >> h;
			if (h <= A) mobs_A.push_back(h);
			else if (h <= B) mobs_B.push_back(h);
			else mobs_C.push_back(h);
		}
		sort(mobs_A.begin(), mobs_A.end());
		sort(mobs_B.begin(), mobs_B.end());
		sort(mobs_C.begin(), mobs_C.end());

		int S = 0;

		while (mobs_A.size() != 0 && mobs_B.size() != 0)
		{
			mobs_A.pop_back();
			mobs_B.pop_back();
			S++;
		}

		if (mobs_A.size() != 0)
		{
			while (mobs_A.size() != 0)
			{
				mobs_A.pop_back();
				if (mobs_A.size() != 0) mobs_A.pop_back();
				S++;
			}
			S += (int) mobs_C.size();
			cout << S << "\n";
		}
		else
		{
			int index_B = 0; int index_C = 0;
			while ((int) mobs_B.size() > index_B)
			{
				int req_B = (mobs_B[index_B] - 1)/A + 1;
				int req_C = 1000000000;
				if ((int)mobs_C.size() > index_C) req_C = (mobs_C[index_C] - 1)/A + 1;

				//cout << req_B << " " << req_C << "\n";

				if (req_B < req_C)
				{
					if (index_B + req_B < mobs_B.size())
					{
						mobs_B[index_B] -= A;
						//cout << "A gets from B " << mobs_B[index_B] << "\n"; 
						if (mobs_B[index_B] <= 0) ++index_B;
					}
				}
				else
				{
					if (index_B + req_C <= mobs_B.size())
					{
						mobs_C[index_C] -= A;
						//cout << "A gets from C " << mobs_C[index_C] << "\n"; 
						if (mobs_C[index_C] <= 0) ++index_C;
					}
				}
				
				mobs_B.pop_back();
				S++;
			}
			S += (int) mobs_C.size();
			S -= index_C;
			cout << S << "\n";
		}
	}

	return 0;
}