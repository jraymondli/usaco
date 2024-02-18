#include <iostream>
#include <set>
#include <list>
#include <cmath>

using namespace std;

const int MAXN = 10002;
int N;
long long a[MAXN];
long long a1[MAXN];
long long d[6];
set<long long> wk_lengths;
set<long long> month_length;

void get_input() {
    cin >> N;
    for (int i=0; i<N; i++) { 
	cin >> a[i];
	month_length.insert(a[i]);
    }
}

bool valid_wl(long long wl)
{
    set<long long> remainders;
    remainders.clear();

    for(int i=0; i<N; i++) {
	if (a[i] < (wl * 4)) return false;
	remainders.insert( a[i] - a[i] / wl * wl);
    }
    return remainders.size() <= 3; 
}

int main() {
    get_input();

    if (month_length.size() <=3) {
	long long minm  = a[0];
	for (int i=1; i<N; i++)
	   minm = min(minm, a[i]); 
	long long U = minm /4;
	cout << U * (U+1) /2 << endl;
	return 0;
    }

    int i = 0;
    for (auto it = month_length.begin(); it != month_length.end(); ++it, i++) {
	a1[i] = *it;
    }
    d[0] = a1[0] - a1[1];
    d[1] = a1[0] - a1[2];
    d[2] = a1[0] - a1[3];
    d[3] = a1[1] - a1[2];
    d[4] = a1[1] - a1[3];
    d[5] = a1[2] - a1[3];
 
    for(int i=0; i<6; i++) { if (d[i]<0) d[i] = - d[i];  }
    for(int i=0; i<6; i++) {
	if(d[i] == 0) continue;
	for(long long j=1; j<= sqrt(d[i]) + 1; j++) {
	    if (d[i] / j * j != d[i]) continue;
	    wk_lengths.insert(j);
	    wk_lengths.insert(d[i]/j);   
	}
    }
    // cout << wk_lengths.size() << endl;
    long long ans = 0;
    for (auto & wl : wk_lengths) {
	if (valid_wl(wl)) ans += wl;
    }
    cout << ans << endl;
    return ans;
}
