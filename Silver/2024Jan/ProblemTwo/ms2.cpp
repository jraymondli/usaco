#include <iostream>
#include <vector>

using namespace std;

/*
 * Ray's solution after reading the sample USACO one 
 */

int N;
const int MAXN = 100002;
vector<int> adj[MAXN];
int P[MAXN];
int ap[MAXN];// available potion
int parent[MAXN];
int n_leaves[MAXN];

void dfs(int u)
{
    for(int v : adj[u]) {
	if ( parent[u] != v) {
	    parent[v] = u;
	    dfs(v);
	}
    } 
}

int grab(int v) {
        while (v > 0) {
                if (ap[v] > 0) {
                        ap[v]--;
                        return 1;
                }
                v = parent[v];
        }
        return 0;
}

void count_leaves(int u)
{
    if (adj[u].size() == 1 && u != 1) { 
	n_leaves[u] = 1;
	return;
    }

    int L = 0;
    for (auto &v : adj[u]) {
	if ( parent[u] != v) {
	    count_leaves(v);
 	    L += n_leaves[v];	
	}
    }
    n_leaves[u] = L;
}

int solv(int u) {
   if (adj[u].size() == 1 && u!= 1 && ap[u]) {	
	return 1;
   }
   int acc = 0;
   for (auto &v : adj[u]) {
	if ( parent[u] != v) {
            acc += solv(v);
	}
   }
   return min(acc + ap[u], n_leaves[u]);
 
}

int main()
{
    cin >> N;

    for(int i=0; i<N; i++) {
	cin >> P[i];
    }
    for(int i=1; i<N; i++) {
	int a, b;
	cin >> a >> b;
	adj[a].push_back(b);
	adj[b].push_back(a);
    }
    dfs(1);
    int numLeaves = 0;
    for (int i=2; i<=N; i++) {
	if (adj[i].size() == 1) numLeaves ++;
    }
    for (int i=0; i<numLeaves; i++) {
	ap[P[i]] ++;	
    } 
    count_leaves(1);
    cout << solv(1) << endl;
 
    // figure out the leaves
    return solv(1);
}


