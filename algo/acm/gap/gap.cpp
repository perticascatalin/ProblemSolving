#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

int T, all_count[10];

int main()
{
	ifstream cin ("gap.in");
    ofstream cout ("gap.out");

    cin >> T;

    while (T--)
    {
    	string number;
    	cin >> number;
    	//cout << number << endl;
    	//cout << number.length() << endl;

    	memset(all_count, 0, sizeof(all_count));
    	for (int i = 0; i < number.length(); ++i)
    		all_count[number[i] - '0']++;

    	vector < pair <int, int> > digit_count; 
    	for (int i = 0; i < 10; ++i)
    		if (all_count[i] > 0) digit_count.push_back(make_pair(i, all_count[i]));

    	if (digit_count.size() == 0)
    	{
    		cout << 0 << endl;
    	}
    	else
    	{
    		long long max_difference = 0;
    		/*
    		for (int i = 0; i < digit_count.size(); ++i)
    		{
    			cout << digit_count[i].first << " " << digit_count[i].second << endl;
    		}
    		*/
    		//cout << "======" << endl;
    		for (int i = 0; i < digit_count.size() - 1; ++i)
    		{
    			int first_digit = digit_count[i].first;
    			int second_digit = digit_count[i+1].first;
    			//cout << first_digit << " " << second_digit << endl;
    			//cout << "FD, SD" << endl;

    			long long first_number = first_digit;
    			long long second_number = second_digit;
    			for (int j = digit_count.size() - 1; j >= 0; --j)
    			{
    				int num_append = digit_count[j].second;
    				if (digit_count[j].first == first_digit) num_append -= 1;
    				//cout << digit_count[j].first << " " << num_append << endl;
    				while (num_append > 0) 
    				{
    					first_number = first_number * 10 + digit_count[j].first;
    					num_append--;
    				}
    			}
    			//cout << "=======" << endl;
    			for (int j = 0; j < digit_count.size(); ++j)
    			{
    				int num_append = digit_count[j].second;
    				if (digit_count[j].first == second_digit) num_append -= 1;
    				//cout << digit_count[j].first << " " << num_append << endl;
    				while (num_append > 0) 
    				{
    					second_number = second_number * 10 + digit_count[j].first;
    					num_append--;
    				}
    			}
    			//cout << first_number << " " << second_number << endl;
    			if (max_difference < second_number - first_number) max_difference = second_number - first_number;
    		}
    		cout << max_difference << endl;
    	}
    }

	return 0;
}