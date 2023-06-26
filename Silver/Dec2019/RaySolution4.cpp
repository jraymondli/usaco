#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
#define all(x) begin(x), end(x)

void setIO(string name) {
	// ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int N,L;
vector<int> w,x,d;
 
void init() {
	setIO("meetings");
	cin >> N >> L;
	w.resize(N), x.resize(N), d.resize(N);
	for(int i =0; i<N; i++)  cin >> w[i] >> x[i] >> d[i];
	vector<int> inds(N); iota(all(inds),0);
	sort(all(inds),[](int a, int b) { return x[a] < x[b]; });
	vector<int> W,X,D;
	for(auto &t : inds) {
	    W.push_back(w[t]);
	    X.push_back(x[t]);
	    D.push_back(d[t]);
	}
	swap(w,W), swap(x,X), swap(d,D);
}
 
int getTime() {
    vector<int> left, right;
    for (int i = 0; i < N; i ++) {
	if (d[i] == -1) left.push_back(x[i]);
	else right.push_back(x[i]);
    }
    vector<pair<int,int>> vxp;
    for (int i =0; i < left.size(); i++) vxp.push_back({left[i], w[i]});
    for (int i =0; i < right.size(); i++) vxp.push_back({L - right[i], w[left.size()+i]}); 
    sort(all(vxp));
    int total = 0;
    for (auto &t : vxp) total += t.second;

    for (auto &t : vxp) {
	total -= 2 * t.second;
	if (total <= 0) return t.first;
    }
}
 
int main() {
	init();
	int t = getTime(); 
	queue<int> rig;
	int ans = 0;
	for (int i = 0; i < N; i ++) {
	    if (d[i] == 1) rig.push(i);
	    else {
		while (rig.size() ) {
		    auto j = rig.front();
		    if ((x[i] - x[j]) <= 2* t) {
		        ans += rig.size();
			break;
		    } else rig.pop();
		}
	    }
        }
	cout << ans << "\n";
}
