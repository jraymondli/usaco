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
long long friends[100][3];

bool check(int w){
    //1 <= x <= X
    //1 <= y <= Y
    //x + y = X + Y - w
    //x = X + Y - y - w
    long long lx = max(1, X - w), hx = min(X + Y - w - 1, X);
    for (int i = 0; i < N; i++){
        long long a = friends[i][0], b = friends[i][1], c = friends[i][2];
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
            cin >> friends[j][0] >> friends[j][1] >> friends[j][2];
        }
        long long lo = 0;
        long long hi = X + Y - 2;
        long long mid;
        while(hi > lo){
            mid = (lo + hi) / 2;
            if (check(mid)) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << "\n";
    }
}
