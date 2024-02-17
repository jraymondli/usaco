#include <iostream>
#include <vector>
 
const int MAXN = 100005;
 
int N;
std::vector<int> adj[MAXN];
int at[MAXN];
int p[MAXN];
int par[MAXN]; // parent
 
void input () {
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> p[i];
	}
	for (int i = 1; i < N; i++) {
		int a, b; std::cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

// figure out the parent 
void dfs (int v) {
	for (auto &u : adj[v]) {
		if (u != par[v]) {
			par[u] = v;
			dfs(u);
		}
	}
}

// can't have more than the leafs 
void proc () {
	int L = 0;    // leaf
	for (int i = 2; i <= N; i++) {
		L += (int(adj[i].size()) == 1);
	}
	for (int i = 0; i < L; i++) {
		at[p[i]]++;
	}
}
 
bool grab (int v) {
	while (v > 0) {
		if (at[v] > 0) {
			at[v]--;
			return 1;
		}
		v = par[v];
	}	
	return 0;
}
 
int solve () {
	int ans = 0;
	for (int i = 2; i <= N; i++) {
		if (int(adj[i].size()) == 1) {
			ans += grab(i);
		}
	}
	return ans;
}
 
int main () {
	input();
	proc();
	dfs(1);
	std::cout << solve() << std::endl;
}


