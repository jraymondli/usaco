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
int child[1501][1501];

int Q;
int x, y;

int total = 0;

void printGrid()
{
    for (int i =0; i < N ; i ++) {
        for (int j =0; j < N; j++)
           cout << grid[i][j];
        cout << endl;
    }
}

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

    for (int i = 0; i < N; i ++) {
	child[i][0] = 0;
    }
    for(int j = 0; j < N; j ++) {
        child[0][j] = 0;
    }
    for(int i = 1; i < N; i ++) {
	for (int j = 1; j < N; j ++) {
	    if(grid[i-1][j] == 'D') child[i][j] += (child[i-1][j] + 1);
	    if(grid[i][j-1] == 'R') child[i][j] += (child[i][j-1] + 1);
	}
    } 
}

int traceVal(int i, int j)
{

    // cout << "N" << N << "{" << i << "," << j << "}" << grid[i][j] << endl;

    if (i == N) return val[N][j];
    if (j == N) return val[i][N];

    if (grid[i][j] == 'R') return traceVal(i, j+1);
    return traceVal(i+1, j);
}

void updateChild(int i, int j, int d)
{
    if (i == N || j == N) return;

    child[i][j] += d;

    if (d > 0) d += 1;
    else d -= 1;

    if (grid[i][j] == 'D')
	updateChild(i +1, j, d);
    else
	updateChild(i, j+1, d);
}


void solve(int i, int j)
{

    int prev = traceVal(i,j);

    if (grid[i][j] == 'D') {
	grid[i][j] = 'R';
	updateChild(i+1, j, - child[i][j] - 1);
	updateChild(i, j+1, child[i][j] + 1);

    } else {

	grid[i][j] = 'D';
	updateChild(i+1, j, child[i][j] + 1);
        updateChild(i, j+1, - child[i][j] -1);
    }

    int curr = traceVal(i, j);

    // cout << "prev" << prev << "curr" << curr << endl;

    total += (child[i][j] +1) * (curr - prev);

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


