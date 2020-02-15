#include <vector>
#include <cstring>

using namespace std;

#define NM 1000005
int used[NM];

class AlienOccupation
{
    public:
    vector <int> getInfo(int N, int A, vector <int> X, vector <int> Y)
    {
        vector <int> planets;
        memset(used, 0, sizeof(used));
        planets.push_back(A);
        used[A] = 1;
        int years = 0;
        int ind = 0;
        int max_year = 0;
        int occupied = 1;
        while (ind < planets.size())
        {
            vector <int> new_planets;
            for (int i = ind; i < planets.size(); ++i)
            {
                int p = planets[i];
                for (int j = 0; j < X.size(); ++j)
                {
                    int new_planet = ((long long)(X[j] * (long long)(p)) + Y[j]) % N;
                    if (!used[new_planet])
                    {
                        new_planets.push_back(new_planet);
                        used[new_planet] = 1;
                        occupied++;
                    }
                }
            }
            int this_year = new_planets.size();
            if (this_year == 0) break;
            max_year = max(max_year, this_year);
            
            ind = planets.size();
            for (int j = 0; j < new_planets.size(); ++j) planets.push_back(new_planets[j]);
            
            ++years;
        }
        vector <int> sol;
        sol.push_back(occupied);
        sol.push_back(years);
        sol.push_back(max_year);
        return sol;
    }
};