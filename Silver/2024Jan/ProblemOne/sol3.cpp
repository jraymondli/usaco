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

    vector<pair<int, int>> q;
    for(int i = 1; i <= N; i++) {
	cin >> c[i];
        was_zero[i] = (c[i] == 0);
    }
	
    int a, h;
    for (int i = 0; i < Q; i++) {
        cin >> a >> h;
	q.push_back(pair(a, h));  	 
    }
    // print(q);
    sort(q.begin(), q.end());
    // print(q);    

    vector<pair<int, int>> fq;  
    int ph = q[0].second;
    fq.push_back(pair(q[0].first, q[0].second));
    for (int i = 1; i < Q; i++) {
        int h = q[i].second;
	if (h == ph) continue;
	ph = h;
	fq.push_back(pair(q[i].first, h)); 
    }
    // print(fq);
    Q = fq.size();

    for(int i = 0; i< (Q-1); i ++ )
    {
	if (fq[i].second > fq[i+1].first) {
	    cout << -1 << endl;
	    return;
        }
    }
 
    for(int i = 0; i< Q; i ++ )
    {
        int a1 = fq[i].first;
  	int h1 = fq[i].second;

  	int ma = 1;
        for (int j=1; j<=a1; j++) {
            ma = max(ma, c[j]);
        }
	int mh = 1;
	for (int j=a1+1; j< h1; j++) {
	   mh = max(mh, c[j]);
	}

	if (ma < mh) {
	    bool set_a_or_before = false;
	    for (int j=a1; j>0; j--) {
		if (was_zero[j]) {
		    c[j] = mh;
		    set_a_or_before = true;
		    break;
		}
	    }
	    if (!set_a_or_before) {
		cout << -1 << endl;
		return;
	    }
        }

	if (was_zero[h1]) {
	    c[h1] = max(c[h1], ma+1);
	} else if (c[h1] <= ma) {
	    cout << -1 << endl;
	    return;
	}	
	
    }

    for (int i = 1; i <= N; i++) {
        if (c[i] > C) {
            cout << -1 << endl;
            return;
        }
    }

    for (int i = 1; i < N; i++) {
	if (c[i] == 0) c[i] = 1;
	cout << c[i] << ' ';
    }
    if (c[N] == 0) c[N] = 1;
    cout << c[N] << endl;
}


int main() {
    cin >> T;
    for (int t = 0; t < T; t++)
	solve();
    return 0;
}
