
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <tuple>
#include <set>
#include <queue>
#include <deque>
#include <cmath>  

#include <iterator>

using namespace std;
int g[100001][3];
int c[100001][3];

int G;
int N;

bool reachable(int i, int j) {
    int dist = abs (g[i][0] - c[j][0]) + abs(g[i][1] - c[j][1]);
    return dist <= abs(g[i][2] - c[j][2]);
}


int main()
{
    cin >> G;
    cin >> N;

    for (int i = 0; i < G; i ++) {
   	cin >> g[i][0] >> g[i][1] >> g[i][2]; 
    }

    for (int j = 0; j < N; j ++) {
  	cin >> c[j][0] >> c[j][1] >> c[j][2];
    }

    int count = 0;

    for (int j = 0; j < N; j ++) {
	bool innocent = false;
	for (int i = 0; i < G; i ++) {
	    if (!reachable(i, j)) innocent = true;
	}
        if (innocent) { 
	    count ++;
            // cout << j << endl;
        }
    }
    cout << count << endl;

}


