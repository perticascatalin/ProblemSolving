#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ifstream fin ("cards_2.in");
	ofstream fout ("cards_2.out");

	int N; fin >> N; 
	int M; fin >> M;
	vector <string> cards;
	for (int i = 0; i < N; ++i)
	{
		string card; 
		fin >> card;
		cards.push_back(card);
	}

	for (int i = 0; i < N; ++i)
		fout << cards[i] << " ";
	fout << "\n";

	for (int j = 0; j < M; ++j)
	{
		int a, b;
		fin >> a >> b;
		--a; --b;
		reverse(cards.begin() + a, cards.begin() + b + 1);
		for (int i = 0; i < N; ++i)
			fout << cards[i] << " ";
		fout << "\n";
	}

	return 0;
}