#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;

#define NMAX 100005

int T;
double expected[NMAX];
int num_divisors[NMAX];

int main()
{
	//int start = clock();

    for (int i = 2; i < NMAX; ++i)
    {
    	num_divisors[i]++;
    	for (int j = 2 * i; j < NMAX; j += i)
    	{
    		num_divisors[j]++;
    		expected[j] += 1.0/num_divisors[i];
    	}
    }

    for (int i = 2; i < NMAX; ++i)
    	expected[i] += expected[i-1];

    ofstream cout("sieve.out");
    cout << fixed << setprecision(4);

    ifstream cin("sieve.in");
    cin >> T;
    while (T--)
    {
    	int n; cin >> n;
    	cout << expected[n] << '\n';
    }

    //int stop = clock();
   	//cout << float(stop - start)/CLOCKS_PER_SEC << endl;

	return 0;
}