#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

ifstream fin ("cards_5.in");
ofstream fout ("cards_5.out");

vector <string> cards;

void print_vector(vector <string> vs)
{
	for (int i = 0; i < vs.size(); ++i)
		fout << vs[i] << " ";
	fout << "\n";
}

void scramble_cards(int a, int b)
{
	int n = b - a + 1;
	int take = n/2;

	vector<string> first_half, second_half;
	first_half.insert(first_half.end(), cards.begin() + a, cards.begin() + a + take);
	second_half.insert(second_half.end(), cards.begin() + a + take, cards.begin() + b + 1);
	cards.erase(cards.begin() + a, cards.begin() + b + 1);

	vector <string> scrambled;
	while (first_half.size() && second_half.size())
	{
		scrambled.push_back(first_half[0]);
		first_half.erase(first_half.begin());
		
		scrambled.push_back(second_half[0]);
		second_half.erase(second_half.begin());
	}
	if (second_half.size()) 
	{
		scrambled.push_back(second_half[0]);
		second_half.erase(second_half.begin());
	}
	
	cards.insert(cards.begin() + a, scrambled.begin(), scrambled.end());
	print_vector(cards);
}

void reverse_cards(int a, int b)
{
	reverse(cards.begin() + a, cards.begin() + b + 1);
	print_vector(cards);	
}

int main()
{
	int N; fin >> N; 
	int M; fin >> M;
	
	for (int i = 0; i < N; ++i)
	{
		string card; 
		fin >> card;
		cards.push_back(card);
	}

	print_vector(cards);

	for (int j = 0; j < M; ++j)
	{
		int a, b;
		string operation;
		fin >> operation >> a >> b;
		--a; --b;
		if (operation == "scramble") scramble_cards(a, b);
		else if (operation == "reverse") reverse_cards(a, b);
	}
	return 0;
}