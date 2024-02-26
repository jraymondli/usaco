#include <iostream>
#include <set>
#include <cmath>

using namespace std;

const int MAXN = 10002;
int N;
int a[MAXN];
int d[6];
set<int> wk_lengths;
int min_month = 0;

void get_input() {
    cin >> N;
    for (int i=0; i<N; i++) cin >> a[i];
}

bool valid_wl(int wl)
{
    set<int> remainders;

    for(int i=0; i<N; i++) {
	if (a[i] < (4 * wl)) return false;
	remainders.insert( a[i] - a[i] / wl * wl);
	if (remainders.size() > 3) return false;
    }
    return true;
}

int main() {
    get_input();
 
    int ans = 0;

    for (int i=1; i<=a[0]/4; i++) {
	if (valid_wl(i)) ans += i;
    }
	
    cout << ans << endl;
    return ans;
}
