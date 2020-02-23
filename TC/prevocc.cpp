#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define MX 1000000

vector <int> B[MX+2];
int Fp[MX];
vector <int> A;

class PreviousOccurrence
{
	public:
	int findValue(int defaultValue, int query)
	{
		A.clear();
		int n = MX;
		for (int i = 0; i <= MX; ++i) B[i].clear();
		memset(Fp, -1, sizeof(Fp));
		A.push_back(0);
		B[0].push_back(0);
		// cout << 0 << endl;
		Fp[0] = 0;

		for (int i = 1; i <= n; ++i)
		{
			int num = A[i-1];
			if (B[num].size() >= 2)
			{
				int dst = B[num][B[num].size() - 1] - B[num][B[num].size() - 2];
				A.push_back(dst);
				
				if (B[dst].size() >= 2)
				{
					B[dst][0] = B[dst][1];
					B[dst][1] = i;
				}
				else B[dst].push_back(i);
				if (Fp[dst] == -1) Fp[dst] = i;
			}
			else
			{
				A.push_back(defaultValue);
				if (B[defaultValue].size() >= 2)
				{
					B[defaultValue][0] = B[defaultValue][1];
					B[defaultValue][1] = i;
				}
				else B[defaultValue].push_back(i);
				if (Fp[defaultValue] == -1) Fp[defaultValue] = i;
			}

			// cout << A[i] << endl;
		}


		int maxi = 0;
		for (int i = 0; i <= 7000; ++i)
		{
			// if (Fp[i] != -1) cout << i << ": " << Fp[i] << endl;
			// else cout << i << ": " << "?" << endl;
			if (Fp[i] == -1) cout << "NOT FOUND " << defaultValue << endl;
			// ! NOT FOUND 1
			maxi = max(maxi, Fp[i]);
		}
		// cout << "MAXI: " << maxi << endl;

		// return Fp[query];
		return maxi;
	}
};

int main()
{
	PreviousOccurrence run;
	// cout << run.findValue(392, 250) << endl;
	int maxi = 0;
	for (int i = 0; i <= 1000; i++)
	{
		cout << i << endl;
		maxi = max(maxi, run.findValue(i, 250));
	}
	cout << "MAXI: " << maxi << endl;
	return 0;
}