#include <iostream>
#include <string>
#include <vector>
    
using namespace std;

class A0Paper
{
    public:
    string canBuild(vector <int> A)
    {
        int n = A.size();
        vector <int> B;
        
        // create a copy of A
        for (int i = 0; i < n; ++i) B.push_back(A[i]);
            
        // concatenate 2 x A[i+1] into an A[i]
        for (int i = n - 1; i > 0; --i) B[i-1] += (B[i]/2);
        
        // if at the end we get more than 1 x A[0], then it is possible
        if (B[0] >= 1) return "Possible";
        else return "Impossible";
    }
};