#include <bits/stdc++.h>
#define NMAX 100005
#define MOD 1000000007

using namespace std;

int v[NMAX];

int main() {
    int t,n,k,dif,i,biggest,times,rest;
    long long prod;

    cin >> t;
    while(t--) {
		cin>>n>>k;

		prod = 1;

		dif = n - ((k+1)*(k+2)/2-1);
		if(dif < -k) cout << "-1\n";
		else if(dif < 0) cout << "0\n";
		else {
			times = dif/k;
			rest = dif%k;

			for(i=1;i<=k;++i) v[i] = i+times+1;
			for(i=k;i>k-rest;--i) ++v[i];

			for(i=1;i<=k;++i) {
				prod*=((1LL*v[i]*(v[i]-1))%MOD);
				prod%=MOD;
			}

			cout << prod << '\n';
		}
    }

    return 0;
}
