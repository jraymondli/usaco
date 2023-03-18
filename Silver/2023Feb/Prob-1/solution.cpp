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
int N, X, Y;
long aa[100], ba[100];
long long ca[100];

bool check(int w){
    //1 <= x <= X
    //1 <= y <= Y
    //x + y = X + Y - w
    //x = X + Y - y - w
    long long lx = max(1, X - w), hx = min(X + Y - w - 1, X);
    for (int i = 0; i < N; i++){
        long a = aa[i]; long b = ba[i]; long long c = ca[i];
        long long d = X + Y - w;
        //a * x + b * y <= c
        //x + y = d = (X + Y - w)
        //-b * x - b * y <= -b * d
        //(a-b) * x <= c - b * d
        if (b - a > 0)
            lx = max(lx, (-c + b * d + (b - a - 1)) / (b - a));
        else if (a - b > 0)
            hx = min(hx, (c - b * d) / (a - b));
        else if (a * d > c) return false;
    }
    return (lx <= hx);
    
}

int main() {
    // ifstream fin ("1.in");
    // ofstream fout ("1.out");
	cin >> T;
    for (int i = 0; i < T; i++){
        cin >> N >> X >> Y;
        for (int j = 0; j < N; j++){
            cin >>  aa[j] >> ba[j] >> ca[j]; 
        }
        int lo = 0;
        int hi = X + Y - 2;
        int mid; 
        while(hi > lo){
            mid = (lo + hi) / 2;
            if (check(mid)) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << "\n";
    }
}
