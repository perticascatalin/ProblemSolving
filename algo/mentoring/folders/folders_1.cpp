#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

ifstream fin ("folders_1.in");
ofstream fout ("folders_2.out");

map <string, vector<string> > FO;
map <string, vector<string> > FI;
map <string, int> N_FO;
map <string, int> N_FI;

int get_num_folders(string name)
{
	if (N_FO.find(name) == N_FO.end()) return 0;
	if (N_FO[name] == -1)
	{
		int num_folders = 0;
		for (int i = 0; i < FO[name].size(); ++i)
		{
			string child_name = FO[name][i];
			if (N_FO[child_name] == -1) num_folders += get_num_folders(child_name);
			else num_folders += N_FO[child_name];
			num_folders++;
		}
		N_FO[name] = num_folders;
	}
	return N_FO[name];
}

int get_num_files(string name)
{
	if (N_FI.find(name) == N_FI.end()) return 0;
	if (N_FI[name] == -1)
	{
		int num_files = 0;
		for (int i = 0; i < FO[name].size(); ++i)
		{
			string child_name = FO[name][i];
			if (N_FI[child_name] == -1) num_files += get_num_files(child_name);
			else num_files += N_FI[child_name];
		}
		num_files += FI[name].size();
		N_FI[name] = num_files;
	}
	return N_FI[name];
}

int main()
{
	int N; fin >> N;
	for (int i = 0; i < N; ++i)
	{
		vector <string> empty_vector;
		string name; fin >> name;
		FO[name] = empty_vector;
		FI[name] = empty_vector;
		N_FO[name] = -1;
		N_FI[name] = -1;
		int num_folders; fin >> num_folders;
		for (int j = 0; j < num_folders; ++j)
		{
			string folder; fin >> folder;
			FO[name].push_back(folder);
		}
		int num_files; fin >> num_files;
		for (int j = 0; j < num_files; ++j)
		{
			string file; fin >> file;
			FI[name].push_back(file);
		}
	}
	// key, value
	// FO/FI[key] = value
	// first: key, second: value
	// for (map <string, vector<string> >::iterator it = FO.begin(); it != FO.end(); ++it)
	// {
	// 	string key = (it->first);
	// 	vector <string> value = (it->second);
	// 	cout << key << "\n";
	// 	for (int i = 0; i < value.size(); ++i) 
	// 		cout << value[i] << " ";
	// 	cout << "\n";
	// }

	// for (map <string, vector<string> >::iterator it = FI.begin(); it != FI.end(); ++it)
	// {
	// 	string key = (it->first);
	// 	vector <string> value = (it->second);
	// 	cout << key << "\n";
	// 	for (int i = 0; i < value.size(); ++i) 
	// 		cout << value[i] << " ";
	// 	cout << "\n";
	// }
	cout << get_num_files("workspace") << "\n";

	return 0;
}