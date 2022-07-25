#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define NM 200005
#define MM 2000005
#define LL long long
#define MOD 1000000007

int last_pos[MM], N;
LL pows[NM], sum[MM], total_sum;

int main()
{
	// Initialize
	LL X = 0;
	memset(last_pos, -1, sizeof(last_pos));
	last_pos[0] = 0;
	sum[0] = 1;
	total_sum = 0;

	freopen ("xorseq.in", "r", stdin);
	freopen ("xorseq.out", "w", stdout);

	scanf("%d\n", &N);

	// Compute powers of 2 modulo MOD
	pows[0] = 1;
	for (int i = 1; i <= N; ++i)
	{
		pows[i] = pows[i-1] * 2LL;
		if (pows[i] >= MOD) pows[i] -= MOD;
	}

	for (int i = 1; i <= N; ++i)
	{
		int A;
		scanf("%d", &A);
		X ^= A;
		if (last_pos[X] != -1)
		{
			int dst = i - last_pos[X];
			if (dst - 1 != 0) // Perform before update
			{
				sum[X] = (sum[X] * pows[dst-1]) % MOD;
			}
			total_sum += sum[X];
			if (total_sum >= MOD) total_sum -= MOD;
			// Perform after update
			sum[X] = (sum[X] * 2LL) + 1;
			if (sum[X] >= MOD) sum[X] -= MOD;
			last_pos[X] = i;
		}
		else
		{
			last_pos[X] = i;
			sum[X] = 1;
		}
	}
	printf("%lld\n", total_sum);
	return 0;
}
