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
    int ans = 0;
    for (int i=2; i<= N; i++) {
	if (adj[i].size() == 1) {
	    ans += grab(i);
	}
    }
    cout << ans << endl;
 
    // figure out the leaves
    return 0;
}


