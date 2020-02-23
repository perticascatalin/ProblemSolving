#include <vector>
#include <cstring>

using namespace std;

#define NM 205
int dxl[205][205][205], dxh[205][205][205], dyl[205][205][205], dyh[205][205][205];

class KRectangleIntersection
{
    long long area(int xl, int xh, int yl, int yh)
    {
        return ((long long)xh - xl) * ((long long)yh - yl);
    }
    
    vector <int> intersect(int xl1, int xh1, int yl1, int yh1, int xl2, int xh2, int yl2, int yh2)
    {
        vector <int> sol;
        sol.push_back(max(xl1,xl2));
       	sol.push_back(min(xh1,xh2));
        sol.push_back(max(yl1,yl2));
       	sol.push_back(min(yh1,yh2));
        return sol;
    }
    
    public:
    long long maxIntersection(vector <int> xl, vector <int> yl, vector <int> xh, vector <int> yh, int k)
    {
        memset(dxl, -1, sizeof(dxl));
        memset(dxh, -1, sizeof(dxh));
        memset(dyl, -1, sizeof(dyl));
        memset(dyh, -1, sizeof(dyh));
        int N = xl.size();
        for (int i = 0; i < N; ++i)
        {
            dxl[i][1][i] = xl[i];
            dxh[i][1][i] = xh[i];
            dyl[i][1][i] = yl[i];
            dyh[i][1][i] = yh[i];
        }
        
        for (int j = 2; j <= k; ++j)
        	for (int i = j-1; i < N; ++i)
            	for (int s = 0; s < N; ++s)
            	{
            		// try without this one
            		dxl[i][j][s] = dxl[i-1][j][s];
            		dxh[i][j][s] = dxh[i-1][j][s];
            		dyl[i][j][s] = dyl[i-1][j][s];
            		dyh[i][j][s] = dyh[i-1][j][s];
            		
            		// choose prev solution
            		for (int ss = 0; ss < N; ++ss)
                    {
                        if (xl[ss] <= xl[s]) continue;
                        vector <int> inter;
                        if (dxl[i-1][j-1][ss] == -1) continue;
                        inter = intersect(xl[i],xh[i],yl[i],yh[i], dxl[i-1][j-1][ss],dxh[i-1][j-1][ss],dyl[i-1][j-1][ss],dyh[i-1][j-1][ss]);
                        if (inter[0] != xl[s]) continue;
                        if (dxl[i][j][s] == -1)
                        {
                            // just copy solution
                            dxl[i][j][s] = inter[0];
                            dxh[i][j][s] = inter[1];
                            dyl[i][j][s] = inter[2];
                            dyh[i][j][s] = inter[3];
                        }
                        else
                        {
                            // if better than last solution
                            long long area1 = area(inter[0],inter[1],inter[2],inter[3]);
                            long long area2 = area(dxl[i][j][s],dxh[i][j][s],dyl[i][j][s],dyh[i][j][s]);
                            
                            if (area1 > area2)
                            {
                                dxl[i][j][s] = inter[0];
                                dxh[i][j][s] = inter[1];
                                dyl[i][j][s] = inter[2];
                                dyh[i][j][s] = inter[3];
                            }
                        }
                    }
        		}
        
        long long max_area = 0;
        for (int s = 0; s < N; ++s)
            max_area = max(max_area, area(dxl[N-1][k][s],dxh[N-1][k][s],dyl[N-1][k][s],dyh[N-1][k][s]));
        return max_area;
    }
};