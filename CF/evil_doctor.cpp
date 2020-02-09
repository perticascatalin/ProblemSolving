#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
 
using namespace std;
 
#define NM 100005
#define DM 3000005
#define MAX 2147483647
 
int N;
int A[NM];
vector <int> nums[DM];
int ch[DM][2], p[DM], is_leaf[DM], best[DM];
int idx;
 
void expand_node(int root, int level)
{
	if (level == -1) 
	{
		is_leaf[root] = 1;
		best[root] = 0;
		return;
	}
	for (int c = 0; c <= 1; ++c)
	{
		idx++;
		ch[root][c] = idx;
		int bit;
		for (int i = 0; i < nums[root].size(); ++i)
		{
			int bit = ((nums[root][i] & (1<<level)) ? 1 : 0);
			if (bit == c) nums[idx].push_back(nums[root][i]);
		}
		if (nums[idx].size() > 0) expand_node(idx, level-1);
		else
		{ 
			is_leaf[idx] = 1;
			best[idx] = 0;
		}
	}
 
	int left = ch[root][0];
	int right = ch[root][1];
 
	if (level == 0)
	{
		int has_0 = (nums[left].size() > 0 ? 1 : 0);
		int has_1 = (nums[right].size() > 0 ? 1 : 0);
		if (has_0 && has_1) best[root] = 1;
		else best[root] = 0;
	}
	else 
	{	
		int to_add = 0;
		if (nums[left].size() > 0 && nums[right].size() > 0) to_add += (1<<level);
		best[root] = min(
		max(to_add + best[right], best[left]),
		max(to_add + best[left], best[right]));
	}
}
 
int main()
{
	ifstream cin("evil_doctor.in");
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> A[i];
	// for (int i = 0; i< N; ++i) cout << A[i] << " "; cout << endl;
 
	memset(ch, 0, sizeof(ch));
 
	idx = 0;
	for (int i = 0; i < N; ++i) nums[0].push_back(A[i]);
 
	int level = 31;
	expand_node(0,level);
 
	// for (int i = 0; i <= idx; ++i)
	// {
	// 	cout << "Node " << i << ": ";
	// 	for (int j = 0; j < nums[i].size(); ++j)
	// 	cout << nums[i][j] << " ";
	// 	cout << "Best: " << best[i] << endl;
	// 	cout << endl;
	// }
 
	// for (int i = 0; i <= idx; ++i) cout << is_leaf[i] << " "; cout << endl;
	cout << best[0] << endl;
 
	return 0;
}