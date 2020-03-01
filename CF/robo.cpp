#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define NM 105

int robo[NM], bio[NM];

int main()
{
	ifstream cin("robo.in");
	int N; cin >> N;
	for (int i = 0; i < N; ++i) cin >> robo[i];
	for (int i = 0; i < N; ++i) cin >> bio[i];

	int ct_robo = 0;
	int ct_bio = 0;
	for (int i = 0; i < N; ++i) if (robo[i] && !bio[i]) ++ct_robo;
	for (int i = 0; i < N; ++i) if (!robo[i] && bio[i]) ++ct_bio;

	if (ct_robo == 0) cout << -1 << endl;
	else
	{
		if (ct_robo > ct_bio) cout << 1 << endl;
		else
		{
			int val = ct_bio - ct_robo;
			val += 1;
			int sol = 0;
			sol += ((val/ct_robo) + 1);
			if (val % ct_robo) sol += 1;
			cout << sol << endl;
		}
	}

	return 0;
}