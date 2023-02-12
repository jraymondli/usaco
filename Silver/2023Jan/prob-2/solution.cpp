#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <tuple>
#include <set>
#include <queue>
#include <deque>

#include <iterator>

using namespace std;

int N;
char grid[1500][1500];
int val[1501][1501];

int Q;
int x, y;

int total = 0;

void update(int i, int j)
{
    int newVal;
    if (grid[i][j] == 'R') {
	newVal = val[i][j+1];
    } else {
	newVal = val[i+1][j];
    }
    total += (newVal - val[i][j]);
    val[i][j] = newVal;
    if  (i > 0 && grid[i-1][j] == 'D')
	update(i - 1, j);
    if (j > 0 && grid[i][j-1] == 'R') 
	update(i, j - 1);
}

void setup()
{
    for(int i = 0; i < N; i ++) {
	if (grid[i][N-1] == 'R') update(i, N-1);
    }
    for(int j = 0; j < N; j ++) {
        if (grid[N-1][j] == 'D') update(N-1, j);
    }
    cout << total << endl; 
}

void solve(int i, int j)
{
    if (grid[i][j] == 'D')
	grid[i][j] = 'R';
    else
	grid[i][j] = 'D';

    update(i, j) ;
    cout << total << endl;
}


int main() {

    cin >> N;
    for (int i = 0; i < N; i++) {
	for (int j = 0; j < N; j ++) {
	    cin >> grid[i][j];
	}
	cin >> val[i][N];
    }
    for (int j = 0; j < N; j ++) 
	cin >> val[N][j];
    setup();

    cin >> Q;
    for (int i = 0; i < Q; i++) {
	int x, y;
	cin >> x >> y;

        solve(x -1, y-1);
    }
     

}


