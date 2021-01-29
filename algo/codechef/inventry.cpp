#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define LL long long
#define mp make_pair

int first_consecutive(string s, int start, int end)
{
	int index = start;
	while (index < end)
	{
		if (s[index] == '#' && s[index + 1] == '#') return index - 1;
		++index;
	}
	return end;
}

int num_consecutive(string s, int start, int end, char symbol)
{
	int num = 0;
	int index = start;
	while (index <= end && s[index] == symbol)
	{
		num++;
		index++;
	}
	return num;
}

string displace(string s, int start, int num_hash)
{
	string ns = s;
	for (int i = start; i <= start + 2*num_hash - 1; i += 2)
	{
		ns[i] = '#';
		ns[i+1] = '.';
	}
	return ns;
}

string reorder(string s, int start, int end, int k)
{
	string ns = s;
	for (int i = start; i <= end; i++)
		if (i <= start + k - 1) ns[i] = '#';
		else ns[i] = '.';
	return ns;
}

LL suma(LL n)
{
	return (LL)(n * (n+1))/2;
}

pair <string, LL> unblock(string s, int start, int end)
{

}

pair <string, LL> solve(string s, int start, int end)
{
	if (num_consecutive(s, start, end, '#') != (end - start + 1) && s[end] == '#') 
	{
		return mp(s, -1);
	}
	int start_index = start;
	// up to start_index) in place
	while (start_index < end && s[start_index] == '#') ++start_index;
	if (start_index == end) 
	{
		return mp(s, 0);
	}
	// start from start_index, which is .
	int end_index = first_consecutive(s, start_index, end);
	// arrange between start_index and end_index
	LL result = 0;
	int how_many = 0;
	for (int i = start_index; i <= end_index; ++i)
		if (s[i] == '#')
		{
			result += (i - start_index - how_many);
			how_many++;
		}
	s = reorder(s, start_index, end_index, how_many);
	// try to solve first_consecutives ###
	// this is between end_index + 1 and end if there are consecutives

	// no consecutives case
	if (end_index == end) 
	{
		return mp(s,result);
	}

	// check if number of consecutive # is less than number of dots after
	int index = end_index + 1;
	int num_hash = num_consecutive(s, index, end, '#');
	int num_dots = num_consecutive(s, index + num_hash, end, '.');

	// not enough dots
	if (num_hash > num_dots) 
	{
		// try to unblock
		
		return mp(s, -1);
	}
	s = displace(s, index, num_hash);
	int begining = num_consecutive(s, start, end, '#');
	result += suma(num_hash-1);
	pair <string, LL> res = solve(s, start + begining, end);
	s = res.first;
	LL rest_of_result = res.second;
	if (rest_of_result == -1) 
	{
		return mp(s, -1);
	}
	return mp(s, result + rest_of_result);
}

int main()
{
	ifstream cin("inventry.in");
	ofstream cout("inventry.out");

	int T; cin >> T;
	while (T--)
	{
		int N; cin >> N;
		string s; cin >> s;
		LL result = solve(s, 0, N-1).second;
		cout << result << "\n";

	}

	return 0;
}