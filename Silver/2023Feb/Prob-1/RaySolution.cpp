#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <queue>
#include <stack>
using namespace std;


int T;

long long N, C, M;

long long a[100], b[100], c[100];


// 1 <= x <= C 
// 1 <= y <= M 
// x + y = C + M - w
bool check(long long w) {

    long long xl, xh;
    xl = max(1LL, C - w);
    xh = min(C, C + M - w -1);

    for (int i = 0; i < N; i ++) {
	long long d = C + M - w;
	if (a[i] < b[i]) {
	    xl = max(xl, (-c[i] + b[i] * d + b[i] - a[i] -1 ) / (b[i] - a[i]));
	    //xl = max(xl, (-c[i] + b[i] * d ) / (b[i] - a[i]));
	} else if (a[i] > b[i]) {
	    xh = min(xh, (c[i] - b[i] * d) / (a[i]-b[i]));
	} else if ( c[i] < a[i] * d) {
	    return false;
	}
    }
    return (xl <= xh);
}

void solve() {
    long lo = 0;
    long hi = C + M - 2;

    while(lo < hi) {
	long long mid = (lo + hi) / 2;
        if (check(mid)) {
	    hi = mid;
        } else {
	    lo = mid + 1;
        }
 
    }
    cout << lo << endl;
}


int main() {
    cin >> T;

    for (int i = 0; i < T; i ++ ) {
	cin >> N >> C >> M;

        for (int j = 0; j < N; j++) {
	    cin >> a[j] >> b[j] >> c [j];
        }

        solve();
    }
}



