#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;
#define NM 10

int N;
int found;
vector <int> sol;

void display_solution() {
	int display[NM][NM]; memset(display, 0, sizeof(display));
	for (int i = 0; i < sol.size(); ++i) display[i][sol[i]] = i+1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) cout << display[i][j] << " ";
		cout << "\n";
	}
}

int valid_solution() {
	for (int i = 0; i < sol.size(); ++i)
		for (int j = i + 1; j < sol.size(); ++j) {
			if (sol[i] == sol[j]) return 0;
			if (abs(i-j) == abs(sol[i]-sol[j])) return 0;
		}
	return 1;
}

void explore(int step) {
	if (step == N) {
		if (valid_solution()) {
			found = 1;
			display_solution();
		}
		return;
	}
	for (int i = 0; i < N; ++i)
	{
		sol.push_back(i);
		explore(step + 1);
		sol.pop_back();
		if (found) return;
	}
}

int main() {
	ifstream cin("q.in");
	cin >> N;
	clock_t begin = clock();
	explore(0);
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Time (sec): " << elapsed_secs << "\n";
	cout << "Solutions found: " << found << "\n";
	return 0;
}