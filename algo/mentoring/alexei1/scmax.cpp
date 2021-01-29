#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define NM 100005
#define inf 2000000005

int N;
int A[NM], SEWL[NM], LONG[NM], WHO[NM];

int main()
{
	ifstream cin ("scmax.in");
	ofstream cout ("scmax.out");

	cin >> N;
	SEWL[0] = LONG[0] = WHO[0] = A[0] = 0;
	
	A[N+1] = inf;
	for (int i = 1; i <= N+1; ++i) 
	{
		SEWL[i] = N+1;
		LONG[i] = 0;
		WHO[i] = 0;
	}
	
	for (int i = 1; i <= N; ++i)
	{
		cin >> A[i];
		int left = 0; int right = i - 1;
		while (left < right - 1)
		{
			int mid = (left + right)/2;
			if (A[SEWL[mid]] < A[i]) left = mid;
			else right = mid - 1;
		}


		if (A[SEWL[right]] < A[i]) left = right;
		int last = SEWL[left];

		WHO[i] = last;
		
		LONG[i] = left + 1;

		
		if (A[i] < A[SEWL[LONG[i]]]) SEWL[LONG[i]] = i;

		
	}
	int maxpos = 0;
	for (int i = 1; i <= N; ++i) 
	{
		if (LONG[i] > LONG[maxpos]) maxpos = i;
	}
	vector <int> solution;
	while (maxpos)
	{
		solution.push_back(A[maxpos]);
		maxpos = WHO[maxpos];
	}
	reverse(solution.begin(), solution.end());
	cout << solution.size() << "\n";
	for (int i = 0; i < solution.size(); ++i) cout << solution[i] << " ";

	return 0;
}