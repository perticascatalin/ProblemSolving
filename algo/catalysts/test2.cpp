#include <fstream>

using namespace std;

int main()
{
	ifstream cin ("level1_0.in");
	ofstream cout ("level1_0.out");

	int T; cin >> T;
	while (T--)
	{
		double a0, b0, a1, b1, r;
		cin >> a0 >> b0 >> a1 >> b1 >> r;
		a0 += 0.5;
		b0 += 0.5;
		a1 += 0.5;
		b1 += 0.5;
		double a = a0 * (1.0 - r) + a1 * r;
		int pa = int(a);
		double b = b0 * (1.0 - r) + b1 * r;
		int pb = int(b);
		cout << pa << " " << pb << "\n";
	}

	return 0;
}