#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
 
using namespace std;
 
#define NM 100005
#define DM 100005
#define MAX 2147483647
 
int N;
int A[NM];
vector <int> nums[DM];
int ch[DM][2], p[DM], is_leaf[DM], best[DM];
int idx;
 
int main()
{
	ifstream cin("evil_doctor.in");
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> A[i];
	// for (int i = 0; i< N; ++i) cout << A[i] << " "; cout << endl;
 	
 	int max_bit = 7;
 	int max_check = (1<<(max_bit+1))-1;

 	cout << max_check << endl;

 	int best = MAX;
 	for (int x = 0; x <= max_check; ++x)
 	{
 		int maximum = 0;
 		for (int i = 0; i < N; ++i)
 			maximum = max(maximum, A[i] ^ x);
 		best = min(best, maximum);
 		cout << x << ": " << maximum << endl;
 	}
 	cout << best << endl;
 
	return 0;
}