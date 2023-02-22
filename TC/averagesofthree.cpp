#include <bits/stdc++.h>
using namespace std;

class AveragesOfThree{
	public: 
    vector <int> restore(vector <int> B){
        vector <int> A;
        A.push_back(0); A.push_back(0);
        int N = B.size();
        for (int i = 0; i < N; ++i) B[i] *= 3;
        int prev = 0;
        N += 2;
        for (int i = 2; i < N; ++i) {
            A.push_back(B[i-2] - prev);
            prev += A[i];
            prev -= A[i-2];
        }
        return A;
    }
};