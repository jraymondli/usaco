#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

int dp[201][201];
int actual[201][201];

int rectangleSum(int a, int b, int x, int y) {
  return actual[a+x][b+y] - actual[a][b+y] - actual[a+x][b] + actual[a][b];
}

int topDP[201];
int bottomDP[201];
int leftDP[201];
int rightDP[201];

int main() {
}


