#include <vector>

using namespace std;

class OppositeParity
{
    public:
    vector <int> rearrange(vector <int> A)
    {
        vector <int> V[2];
        int N = A.size();
        for (int i = 0; i < N; ++i)
            V[A[i]%2].push_back(A[i]);
        vector <int> B;
        if (V[0].size() != V[1].size()) return B;
        else
        {
            for (int i = 0; i < N; ++i)
                if (A[i] % 2)
            	{
                	B.push_back(V[0][V[0].size() - 1]);
                	V[0].pop_back();
            	}
            	else
                {
                	B.push_back(V[1][V[1].size() - 1]);
                	V[1].pop_back();           
                }
            return B;
        }
    }
};