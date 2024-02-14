#include <iostream>
using namespace std;
#include <vector>
#include <bits/stdc++.h>

int T;
int N, Q, C;

void print(vector<pair<int, int>> &lst) {
    for (auto &e : lst) {
       cout << "(" << e.first << ',' << e.second << ")" << ";" ;
    }
    cout << endl;
}

void solve()
{
    cin >> N >> Q >> C;
    int c[N+1];
    bool was_zero[N+1];
    int B[N+1]; for (int i = 0; i <= N; i++) B[i] = 0;

    vector<pair<int, int>> q;
    for(int i = 1; i <= N; i++) {
	cin >> c[i];
        was_zero[i] = (c[i] == 0);
    }
	
    int a, h;
    for (int i = 0; i < Q; i++) {
        cin >> a >> h;  B[a] = h;
	q.push_back(pair(a, h));  	 
    }
    sort(q.begin(), q.end());

    vector<pair<int, int>> fq;  
    int ph = q[0].second;
    fq.push_back(pair(q[0].first, q[0].second));
    for (int i = 1; i < Q; i++) {
        int h = q[i].second;
	if (h == ph) continue;
	ph = h; fq.push_back(pair(q[i].first, h)); 
    }
    for (int i = 1; i <= N; i++) { if (c[i] == 0) c[i] = 1; }
    for (int i=1; i<=N; i++) {
        for (int j=i+1; j<B[i]; j++) {
	    if (B[j] && (B[j] != B[i])) { cout << -1 << endl; return; }
	    B[j] = B[i];
	}
    }
    for (int i=1; i<=N; i++) {
	if (B[i] == 0) continue;
	int max_before=0, max_after=0;
	for (int j=1; j<=i; j++) max_before = max(max_before, c[j]);
  	for (int j=i+1; j<B[i]; j++) max_after = max(max_after, c[j]);	 
        bool found_update = false;
	if (max_after > max_before) {
	    for (int j=i; j>=1; j--) {
		if (B[j] && B[j] < B[i]) { cout << -1 << endl; return; }
		if (!was_zero[j]) continue; 
		c[j] = max_after;
		found_update = true;
		break;
	    }
	    max_before = max_after;
	    if (!found_update) { cout << -1 << endl; return; }
	}
	if (was_zero[B[i]]) c[B[i]] = max_before + 1;
	if (c[B[i]] <= max_before) { cout << -1 << endl; return; }
    }
    for (int i=1; i<=N; i++) { if (c[i]>C) { cout << -1 << endl; return; } }
    for (int i = 1; i < N; i++) {
	cout << c[i] << ' ';
    }
    cout << c[N] << endl;
}


int main() {
    cin >> T;
    for (int t = 0; t < T; t++)
	solve();
    return 0;
}
