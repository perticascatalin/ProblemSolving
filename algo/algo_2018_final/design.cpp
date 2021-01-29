#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define NMAX 505
#define KMAX 10

using namespace std;

int N, K;

vector <int> G[NMAX]; // initial graph
vector <int> A[NMAX]; // tree with root 1
int E[NMAX][KMAX]; // required number of color count per node
int up[NMAX], viz[NMAX]; // up node in the tree, whether visited
int P[NMAX][KMAX][KMAX]; // can satisfy constraints for node, given color_up and color_node
vector <pair<int, int> > assig[NMAX][KMAX][KMAX];


// Maximum Flow functionality
#define NM 1010
#define PB push_back
#define inf 2000000000
 
int C[NM][NM], F[NM][NM], flux, NUM, M;
int ABC[NM][3];
vector <int> Graf[NM];
 
int poti_pompa()
{
    int coada[NM], vizitat[NM], t[NM], st = 0, dr = -1;
 
    memset (vizitat, 0, sizeof(vizitat));
 
    coada[++dr] = 1;
    vizitat[1] = 1;
    t[1] = 0;
 
    while (st <= dr)
    {
        int nod = coada[st];
        ++st;
 
        if (nod == NUM) break;
 
        for (int i = 0; i < Graf[nod].size(); ++i)
        {
            int nnod = Graf[nod][i];
            if (vizitat[nnod]) continue;
            if (!(C[nod][nnod] - F[nod][nnod])) continue;
            coada[++dr] = nnod;
            vizitat[nnod] = 1;
            t[nnod] = nod;
        }
    }
 
    if (!vizitat[NUM]) return 0;
 
    int nod = NUM, flux_plus = inf;
 
    while (t[nod])
    {
        int tnod = t[nod];
        flux_plus = min (flux_plus, C[tnod][nod] - F[tnod][nod]);
        nod = tnod;
    }
 
    flux += flux_plus;
 
    nod = NUM;
 
    while (t[nod])
    {
        int tnod = t[nod];
        F[tnod][nod] += flux_plus;
        F[nod][tnod] -= flux_plus;
        nod = tnod;
    }
 
    return 1;
}
 
int flux_maxim()
{
    //freopen ("maxflow.in", "r", stdin);
    //freopen ("maxflow.out", "w", stdout);
 
    //scanf ("%d %d", &NUM, &M);
    // transferred golbally
 
    for (int i = 1; i <= M; ++i)
    {
        int a, b, c;
        //scanf ("%d %d %d", &a, &b, &c);
        // transferred globally
        a = ABC[i][0];
        b = ABC[i][1];
        c = ABC[i][2];
 
        Graf[a].PB(b);
        Graf[b].PB(a);
 
        C[a][b] += c;
    }
 
    while (poti_pompa());

    return flux;
}

pair<int, vector<int> > make_assignment(int satisfy_E[], vector <vector<int> > satisfy_P, 
	vector <pair < vector<pair<int, int> >, pair<int, int> > > satisfy_assigs)
{
	//printf ("making assignment\n");
	int C_NUM = satisfy_P.size();
	//printf ("number of child nodes %d\n", C_NUM);
	int source = 1;

	// first layer
	int start_cnum = source + 1;
	int end_cnum = source + C_NUM;

	// second layer
	int start_cnum_col = end_cnum + 1;
	int end_cnum_col = end_cnum + C_NUM * K;

	// third layer
	int start_col = end_cnum_col + 1;
	int end_col = end_cnum_col + K;

	int dest = end_col + 1;
	NUM = dest;
	//printf("Flux nodes %d \n", NUM);

	int last_index = -1;
	int current_node = 1;
	int index_to_flux_node[NMAX];
	memset(index_to_flux_node, 0, sizeof(index_to_flux_node));
	int index_color_to_flux_node[NMAX][KMAX];
	//int flux_node_to_index[NM][2];

	for (int i = 0; i < satisfy_assigs.size(); ++i)
	{
		if (satisfy_assigs[i].first.size() == 0) continue;
		int cur_index = satisfy_assigs[i].second.first;
		// add it as a first layer node
		if (cur_index != last_index)
		{
			++current_node;
			++M;
			ABC[M][0] = source;
			ABC[M][1] = current_node;
			ABC[M][2] = 1;
			index_to_flux_node[cur_index] = current_node;
			//flux_node_to_index[current_node][0] = cur_index;
		}
		last_index = cur_index;
	}
	// Add nodes for indexes that are not satisfied at all
	for (int i = 0; i < C_NUM; ++i)
		if (index_to_flux_node[i] == 0)
		{
			int cur_index = i;
			current_node++;
			++M;
			ABC[M][0] = source;
			ABC[M][1] = current_node;
			ABC[M][2] = 1;
			index_to_flux_node[cur_index] = current_node;
			//flux_node_to_index[current_node][0] = cur_index;
		}

	for (int i = 0; i < satisfy_assigs.size(); ++i)
	{
		// add second layer node: node color node
		// add third layer node: color node
		int cur_index = satisfy_assigs[i].second.first;
		int cur_color = satisfy_assigs[i].second.second;
		current_node = index_to_flux_node[cur_index];
		int target_node = start_cnum_col + (current_node - 2) * K + cur_color - 1;
		index_color_to_flux_node[cur_index][cur_color] = target_node;

		if (satisfy_P[cur_index][cur_color])
		{
			++M;
			ABC[M][0] = current_node;
			ABC[M][1] = target_node;
			ABC[M][2] = 1;
			
			//flux_node_to_index[target_node][0] = cur_index;
			//flux_node_to_index[target_node][1] = cur_color;

			++M;
			int color_node = start_col + cur_color - 1;
			ABC[M][0] = target_node;
			ABC[M][1] = color_node;
			ABC[M][2] = 1;
		}
	}

	// add last layer: satisfy_E
	for (int color = 1; color <= K; ++color)
	{
		if (satisfy_E[color] == 0) continue;
		++M;
		int color_node = start_col + color - 1;
		ABC[M][0] = color_node;
		ABC[M][1] = dest;
		ABC[M][2] = satisfy_E[color];
	}

	/*
	for (int i = 1; i <= M; ++i) printf("(%d, %d, %d) ", ABC[i][0], ABC[i][1], ABC[i][2]);
	printf ("\n");
	*/
	int obt_flux = flux_maxim();
	//printf ("Obtained flux %d out of %d\n", obt_flux, C_NUM);

	int assig_posib = 1;

	if (obt_flux != C_NUM) assig_posib = 0;
	vector <int> index_to_color;

	//printf ("Before index assig\n");
	for (int i = 0; i < C_NUM; ++i)
	{
		int index_node = index_to_flux_node[i];
		int assigned_color = 0;
		for (int color = 1; color <= K; ++color)
		{	
			int target_node = index_color_to_flux_node[i][color];
			if (F[index_node][target_node] == 1)
			{
				assigned_color = color;
				break;
			}
		}
		if (assigned_color) index_to_color.push_back(assigned_color);
	}
	//printf ("After index assig\n");

	// clean-up flux data
	memset(C, 0, sizeof(C));
    memset(F, 0, sizeof(F));
    for (int i = 1; i <= NUM; ++i) Graf[i].clear();
    M = 0;
	NUM = 0;
	flux = 0;

	return make_pair(assig_posib, index_to_color);
}

int main()
{
	// Read the data
	freopen ("design4.in", "r", stdin);
    freopen ("design.out", "w", stdout);

    scanf("%d %d", &N, &K);

    memset(E, 0, sizeof(E));

    for (int i = 1; i <= N; ++i)
    {
    	int X, color, neighbor;
    	scanf("%d", &X);
    	for (int j = 1; j <= X; ++j)
    	{
    		scanf ("%d", &color);
    		E[i][color]++;
    	}
    	for (int j = 1; j <= X; ++j)
    	{
    		scanf("%d", &neighbor);
    		G[i].push_back(neighbor);
    	}
    	sort(G[i].begin(), G[i].end());
    	/*
    	for (int j = 1; j <= K; ++j) printf("%d ", E[i][j]);
    	printf ("\n");
    	
    	for (int j = 0; j < G[i].size(); ++j) printf("%d ", G[i][j]);
    	printf ("\n");
    	*/
    }
    E[1][0] = 1; // blank color for up node 1

    // Create tree structure with root node 1
    queue <int> Q;
    memset(viz, 0, sizeof(viz));
    up[1] = 0;
    Q.push(1);
    viz[1] = 1;
    int index = 1;
    vector <pair<int, int> > order; // P compute order
 	order.push_back(make_pair(-index, 1));

    while (!Q.empty())
    {
        int node = Q.front();
        //printf ("%d ", node);
        Q.pop();
        for (int i = 0; i < G[node].size(); ++i)
        {
            int n_node = G[node][i];
            if (viz[n_node]) continue;
            up[n_node] = node;
            A[node].push_back(n_node);
            Q.push(n_node);
            viz[n_node] = 1;
            index++;
            order.push_back(make_pair(-index, n_node));
        }
    }
    sort(order.begin(), order.end());
    //for (int i = 0; i < order.size(); ++i) printf("%d \n", order[i].second);

    // Compute possibility to satisfy constraints
    memset(P, 0, sizeof(P));
    for (int o = 0; o < order.size(); ++o)
    {
    	int node = order[o].second;
    	for (int color_up = 0; color_up <= K; ++color_up) // color_up starts from 0 in the case of root
    	{
    		if (E[node][color_up] == 0) continue; // can't assign color_up to parent
    		for (int color_node = 1; color_node <= K; ++color_node)
    		{
    			int can_color = 1;
    			for (int i = 0; i < A[node].size(); ++i)
    			{
    				int n_node = A[node][i];
    				if (E[n_node][color_node] == 0)
    				{
    					can_color = 0; // child node does not have that color
    					break;
    				}
    			}
    			// cannot color w. color_node
    			if (can_color == 0) continue;

    			// try to color
    			if (A[node].size() == 0) 
    			{
    				P[node][color_up][color_node] = 1; // leaf node
    				vector< pair<int, int> > cur_assig;
    				cur_assig.push_back(make_pair(node, color_node));
    				assig[node][color_up][color_node] = cur_assig;
    				//printf ("leaf node %d, color_up %d, color_node %d\n", node, color_up, color_node);
    			}
    			else
    			{	
    				// do assignment on child nodes with 
    				// P[n_node][color_node][color] color = color of child node
    				// to satisfy E[node][...] without color_up

    				// desired output
    				// iterate over node color constraints
    				int satisfy_E[KMAX];
    				for (int color = 0; color <= K; ++color)
    					satisfy_E[color] = E[node][color];
    				satisfy_E[color_up] -= 1; // subtract assigned parent color

    				// given input
    				// iterate over node children
    				vector <vector<int> > satisfy_P;
    				vector <pair < vector<pair<int, int> >, pair<int, int> > > satisfy_assigs;
	    			for (int i = 0; i < A[node].size(); ++i)
	    			{
	    				int n_node = A[node][i];

	    				vector <int> n_node_P;
	    				n_node_P.push_back(0); // blank color for index match
	    				for (int color = 1; color <= K; ++color)
	    				{
	    					n_node_P.push_back(P[n_node][color_node][color]);
	    					satisfy_assigs.push_back(make_pair(assig[n_node][color_node][color], make_pair(i, color)));
	    				}
	    				satisfy_P.push_back(n_node_P);
	    			}
	    			/*
	    			printf ("satisfy node %d, color_up %d, color_node %d\n", node, color_up, color_node);
	    			printf ("satisfy E\n");
	    			for (int color = 0; color <= K; ++color) printf("%d ", satisfy_E[color]);
	    			printf ("\n");
	    			printf ("satisfy P\n");
	    			for (int i = 0; i < satisfy_P.size(); ++i)
	    			{
	    				for (int color = 0; color <= K; ++color) printf ("%d ", satisfy_P[i][color]);
	    				printf ("\n");
	    			}
	    			*/
	    			// Make assignment based on priorty of assignments of sub-nodes x colors
	    			// Order their assignment vectors

	    			sort(satisfy_assigs.begin(), satisfy_assigs.end());
	    			
	    			/*
	    			printf("satisfy assig\n");
	    			for (int i = 0; i < satisfy_assigs.size(); ++i)
	    			{
	    				printf ("index %d color %d, ", satisfy_assigs[i].second.first, satisfy_assigs[i].second.second);
	    				for (int j = 0; j < satisfy_assigs[i].first.size(); ++j)
	    					printf ("(%d, %d) ", satisfy_assigs[i].first[j].first, satisfy_assigs[i].first[j].second);
	    				printf ("\n");
	    			}
	    			*/
	    			pair <int, vector<int> > answer;
	    			answer = make_assignment(satisfy_E, satisfy_P, satisfy_assigs);
	    			if (answer.first)
	    			{
	    				//printf ("Possible to assign\n");
	    				vector<int> index_to_color;
	    				index_to_color = answer.second;
	    				/*
	    				printf ("Color assignment \n");
	    				for (int i = 0; i < index_to_color.size(); ++i) printf("%d ", index_to_color[i]);
	    				printf ("\n");
	    				*/

	    				for (int i = 0; i < A[node].size(); ++i)
		    			{
		    				int n_node = A[node][i];

		    				vector <pair<int, int> > part_assig;
		    				part_assig = assig[n_node][color_node][index_to_color[i]];
		    				for (int j = 0; j < part_assig.size(); ++j)
		    					assig[node][color_up][color_node].push_back(part_assig[j]);
		    			}
		    			assig[node][color_up][color_node].push_back(make_pair(node, color_node));
		    			sort(assig[node][color_up][color_node].begin(), assig[node][color_up][color_node].end());
		    			P[node][color_up][color_node] = 1;
	    			}
	    			//else printf ("Not possible to assign\n");
	    		}
    		}
    	}
    }

    for (int color = 1; color <= K; ++color)
    	if (P[1][0][color] == 1)
    	{
    		//printf ("color %d -> ", color);
    		for (int i = 0; i < assig[1][0][color].size(); ++i) printf ("%d ", assig[1][0][color][i].second);
    		//printf ("\n");
    		break;
    	}

	return 0;
}