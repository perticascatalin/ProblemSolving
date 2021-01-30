// Aceasta sursa provine de la alti autori, scopul este de a testa ca ia 100p

#include <fstream>
#include <algorithm>
#include <iostream>
#include <vector>
 
std::ifstream in("mobs.in");
std::ofstream out("mobs.out");
 
int main() {
    int T;
    in >> T;
 
    while (T--) {
        int N, A, B;
        in >> N >> A >> B;
 
        if (A > B) {
            std::swap(A, B);
        }
 
        std::vector<int> mobs_A, mobs_B, mobs_C;
 
        for (int i = 0; i < N; i++) {
            int x;
            in >> x;
            if (x <= A) {
                mobs_A.push_back(x);
            }
            if (x > A && x <= B) {
                mobs_B.push_back(x);
            }
            if (x > A && x > B) {
                mobs_C.push_back(x);
            }
        }
 
        std::sort(mobs_A.begin(), mobs_A.end());
        std::sort(mobs_B.begin(), mobs_B.end());
        std::sort(mobs_C.begin(), mobs_C.end());
 
        int TOTAL = 0;
        while (mobs_A.size() != 0 && mobs_B.size() != 0) {
            mobs_A.pop_back();
            mobs_B.pop_back();
 
            TOTAL++;
        }
 
        if (mobs_B.size() == 0) {
            while (mobs_A.size() != 0) {
                mobs_A.pop_back();
                if (mobs_A.size()) {
                    mobs_A.pop_back();
                }
 
                TOTAL++;
            }
 
            TOTAL += (int) mobs_C.size();
        } else {
 
            int index = 0, index2 = 0;
            while (mobs_B.size() > index2) {
                mobs_B.pop_back();
                TOTAL++;
 
                if (mobs_C.size() > index && mobs_C[index] <= A * 2) {
                    mobs_C[index] -= A;
                    if (mobs_C[index] <= 0) {
                        index++;
                    }
                } else {
                    if (mobs_B.size() > index2) {
                        mobs_B[index2] -= A;
                        if (mobs_B[index2] <= 0) {
                            index2++;
                        }
                    }
                }
            }
 
            TOTAL += mobs_C.size();
            TOTAL -= index;
        }
 
        std::cout << TOTAL << "\n";
        out << TOTAL << "\n";
    }
}
