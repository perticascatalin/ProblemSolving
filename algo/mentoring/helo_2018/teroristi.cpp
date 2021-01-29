#include <iostream>
#include <fstream>  
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
 
using namespace std;
 
#define NM 2005
#define PB push_back
#define inf 2000000000
 
int C[NM][NM], F[NM][NM], flux, N;
vector <int> G[NM];

int L, M;
string word;
pair <char, char> bichar[NM];
 
int poti_pompa()
{
    int coada[NM], viz[NM], t[NM], st = 0, dr = -1;
 
    memset (viz, 0, sizeof(viz));
 
    coada[++dr] = 1;
    viz[1] = 1;
    t[1] = 0;
 
    while (st <= dr)
    {
        int nod = coada[st];
        ++st;
 
        if (nod == N) break;
 
        for (int i = 0; i < G[nod].size(); ++i)
        {
            int nnod = G[nod][i];
            if (viz[nnod]) continue;
            if (!(C[nod][nnod] - F[nod][nnod])) continue;
            coada[++dr] = nnod;
            viz[nnod] = 1;
            t[nnod] = nod;
        }
    }
 
    if (!viz[N]) return 0;
 
    int nod = N, flux_plus = inf;
 
    while (t[nod])
    {
        int tnod = t[nod];
        flux_plus = min (flux_plus, C[tnod][nod] - F[tnod][nod]);
        nod = tnod;
    }
 
    flux += flux_plus;
 
    nod = N;
 
    while (t[nod])
    {
        int tnod = t[nod];
        F[tnod][nod] += flux_plus;
        F[nod][tnod] -= flux_plus;
        nod = tnod;
    }
 
    return 1;
}
 
int main()
{
    
 
    ifstream fin ("teroristi.in");
    ofstream fout ("teroristi.out");

    fin >> L >> M;
    fin >> word;

    for (int i = 1; i <= M; ++i)
    {
        char space, a, b;
        fin >> a >> b;
        bichar[i] = make_pair(a, b);
        //cout << bichar[i].first << " " << bichar[i].second << "\n";
    }


    memset (C, 0, sizeof(C));
    memset (F, 0, sizeof(F));

    // 1 - source
    // 2, M + 1 bichar
    // M + 2, M + L + 1 word
    // M + L + 2 = N destination
    
    int source = 1;
    N = M + L + 2;
    for (int i = 2; i <= M + 1; ++i)
    {
        G[source].PB(i);
        G[i].PB(source);
        C[source][i] += 1;
    }

    for (int i = 2; i <= M + 1; ++i)
        for (int j = M + 2; j <= M + L + 1; ++j)
            if (bichar[i-1].first == word[j - M - 2] || bichar[i-1].second == word[j - M - 2])
            {
                G[i].PB(j);
                G[j].PB(i);
                C[i][j] += 1;
            }

    for (int j = M + 2; j <= M + L + 1; ++j)
    {
        G[j].PB(N);
        G[N].PB(j);
        C[j][N] += 1;
    }

    while (poti_pompa());
 
    //cout << flux << "\n";
    for (int j = M + 2; j <= M + L + 1; ++j)
        for (int i = 2; i <= M + 1; ++i)
            if (F[i][j]) fout << (i - 1) << " ";
 
    return 0;
}