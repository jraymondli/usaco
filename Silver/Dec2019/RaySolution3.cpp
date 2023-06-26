#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi; 
typedef vector<pair<int,int>> vpi; 
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second

void setIO(string name) {
	// ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int N,L;
vi w,x,d;
 
void init() {
	setIO("meetings");
	cin >> N >> L;
	w.rsz(N), x.rsz(N), d.rsz(N);
	F0R(i,N) cin >> w[i] >> x[i] >> d[i];
	vi inds(N); iota(all(inds),0);
	sort(all(inds),[](int a, int b) { return x[a] < x[b]; });
	vi W,X,D;
	trav(t,inds) {
		W.pb(w[t]);
		X.pb(x[t]);
		D.pb(d[t]);
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
    for (auto &t : vxp) total += t.s;

    for (auto &t : vxp) {
	total -= 2 * t.s;
	if (total <= 0) return t.f;
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
