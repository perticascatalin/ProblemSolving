#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define NM 100005

int N, Q;
int A[NM], B[NM], C[NM];

int main()
{
	// Read the data
	freopen ("copii3.in", "r", stdin);
    freopen ("copii3.out", "w", stdout);

    scanf("%d %d\n", &N, &Q);

    B[0] = 0;
    C[0] = 0;
    for (int i = 1; i <= N; ++i)
    {
    	char c;
    	scanf("%c", &c);
    	A[i] = c - '0';
    	B[i] = A[i] + B[i-1];
    	C[i] = (1-A[i]) + C[i-1];
    }
    //for (int i = 1; i <= N; ++i) printf("%d", A[i]);
    int L, R;
    for (int i = 1; i <= Q; ++i)
    {
    	scanf("%d %d", &L, &R);
    	//printf ("%d %d\n", L, R);
    	if ((B[R] - B[L-1]) > (C[L-1] + C[N] - C[R])) printf("-1\n");
    	else
    	{
    		//printf("DK\n");
    		int index_left = L - 1;
    		int index_right = R + 1;
    		int index_L = L;
    		int index_R = R;

    		int score = 0;
    		while (index_L <= index_R)
    		{
    			while (index_L <= index_R && A[index_L] != 1) ++index_L;
    			if (index_L > index_R) break;

    			while (index_R >= index_L && A[index_R] != 1) --index_R;
    			if (index_R < index_L) break;

    			while (index_left > 0 && A[index_left] != 0) --index_left;
    			while (index_right <= N && A[index_right] != 0) ++index_right;

    			
    			int left_score = 100000;
    			if (index_left > 0) left_score = index_L - index_left;
    			int right_score = 100000;
    			if (index_right <= N) right_score = index_right - index_R;
    			if (left_score < right_score)
    			{
    				score += left_score;
    				index_L++;
    				index_left--;
    			}
    			else
    			{
    				score += right_score;
    				index_R--;
    				index_right++;
    			}
    		}
    		printf ("%d\n", score);
    	}
    }


	return 0;
}