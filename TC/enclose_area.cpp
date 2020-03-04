#include <iostream>
#include <string>
#include <vector>

using namespace std;

class EncloseArea
{
	public:
	vector<string> enclose(int A)
	{
		vector<string> sol;
		int r = 2;
		if (A % 2 || A / 2 > (25 * 25 + 24 * 24)) return sol;
		else
		{
			int tiles = A/2;
			int rows = tiles/(25 + 24);
			int add_cols = tiles % (25 + 24);
			if (rows >= 1)
			{
				// can generate first line
				string line1 = "";
				for (int i = 0; i < 50; ++i)
				{
					if (i % 2) line1 += "\\";
					else line1 += "/";
				}
				sol.push_back(line1);

				cout << rows << endl;
				cout << add_cols << endl;
				// for the remaining rows, \....../ or /......\
				while (r <= 2 * rows)
				{
					string bg, en;
					if (r % 2) 
					{
						bg = "/";
						en = "\\";
					}
					else
					{
						bg = "\\";
						en = "/";
					}
					string line = bg;
					for (int i = 1; i < 50 - 1; ++i) line += ".";
					line += en;
					sol.push_back(line);
					++r;
				}

				// redo last line
				if (add_cols == 0)
				{
					string line = "";
					for (int i = 0; i < 50; ++i) 
						if (i % 2) line += "/";
						else line += "\\";
					sol[sol.size() - 1] = line;
				}
				else
				{
					if (add_cols % 2 == 0)
					{
						string line2 = "/";
						for (int i = 1; i < add_cols; ++i) line2 += ".";
						line2 += "/";
						for (int i = add_cols; i <= 50 - 2; ++i) line2 += ".";
						sol.push_back(line2);
						// Redo previous line
						int ind = sol.size() - 2;
						for (int i = add_cols + 1; i < 50; ++i) 
							if (i % 2) sol[ind][i] = '/';
							else sol[ind][i] = '\\';
						string line3 = "";
						for (int i = 1; i <= add_cols; ++i)
							if (i % 2) line3 += "\\";
							else line3 += "/";
						for (int i = add_cols + 1; i <= 50; ++i) line3 += ".";
						sol.push_back(line3);
					}
					else
					{
						string line2 = "/";
						for (int i = 1; i <= add_cols - 1; ++i) line2 += ".";
						line2 += "\\";
						for (int i = add_cols; i <= 50 - 2; ++i) line2 += ".";
						sol.push_back(line2);

						// Redo previous line
						int ind = sol.size() - 2;
						for (int i = add_cols; i < 50; ++i) 
							if (i % 2) sol[ind][i] = '/';
							else sol[ind][i] = '\\';
						string line3 = "";
						for (int i = 1; i <= add_cols + 1; ++i)
							if (i % 2) line3 += "\\";
							else line3 += "/";
						for (int i = add_cols + 2; i <= 50; ++i) line3 += ".";
						sol.push_back(line3);			
					}
				}
				return sol;
			}
			// need to redo this case entirely
			else
			{
				if (add_cols % 2 == 0)
				{
					string line2 = "/";
					for (int i = 1; i < add_cols; ++i) 
						if (i % 2) line2 += "\\";
						else line2 += "/";
					for (int i = add_cols; i <= 50 - 2; ++i) line2 += ".";
					sol.push_back(line2);

					string line3 = "\\";
					for (int i = 1; i < add_cols; ++i) line3 += ".";
					line3 += "\\";
					for (int i = add_cols + 1; i < 50 - 1; ++i) line3 += ".";
					sol.push_back(line3);

					string line4 = ".";
					for (int i = 1; i <= add_cols; ++i)
						if (i % 2) line4 += "\\";
						else line4 += "/";
					for (int i = add_cols; i < 50 - 2; ++i) line4 += ".";
					sol.push_back(line4);
				}
				else
				{
					string line2 = "/";
					for (int i = 1; i <= add_cols - 1; ++i)
						if (i % 2) line2 += "\\";
						else line2 += "/";
					line2 += "\\";
					for (int i = add_cols; i <= 50 - 2; ++i) line2 += ".";
					sol.push_back(line2);

					string line3 = "\\";
					for (int i = 1; i < add_cols; ++i) line3 += ".";
					line3 += "/";
					for (int i = add_cols + 2; i <= 50; ++i) line3 += ".";
					sol.push_back(line3);

					string line4 = ".";
					for (int i = 1; i < add_cols; ++i)
						if (i % 2) line4 += "\\";
						else line4 += "/";
					for (int i = add_cols; i < 50; ++i) line4 += ".";
					sol.push_back(line4);

				}
				return sol;
			}
		}
	}
};

int main()
{
	EncloseArea run;
	vector <string> sol = run.enclose(10);
	for (int i = 0; i < sol.size(); ++i) cout << sol[i] << endl;
	return 0;
}