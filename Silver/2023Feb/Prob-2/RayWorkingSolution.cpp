
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

struct Point {
   long long x;
   long y;
   long t;
};

struct Point g[100001];
struct Point a[100001];

int G;
int N;

bool CompareGraze(const Point &g1, const Point &g2) 
{
    return g1.t < g2.t;
}

void printGraze()
{
    for (int i = 0; i < G; i ++) {
	cout << g[i].t << endl;
    }
}

bool reachable(struct Point g1, struct Point g2) {
     long long  dist = (g1.x - g2.x)*(g1.x - g2.x) + (g1.y - g2.y) * (g1.y - g2.y);
     return dist <= (g1.t - g2.t) * (g1.t - g2.t);
    
}

int findPos(int t) {
   if (t > g[G-1].t) return G;

   int l = 0, h = G - 1;
   while (l < h) {
     int mid = (l + h) / 2;
     if (g[mid].t  == t) return mid ;

     if (g[mid].t > t) h = mid;
     else l = mid + 1;

   }

   return l;
}

int main()
{
    cin >> G;
    cin >> N;

    for (int i = 0; i < G; i ++) {
	cin >> g[i].x >> g[i].y >> g[i].t;
    }

    for (int j = 0; j < N; j ++) {
	cin >> a[j].x >> a[j].y >> a[j].t;
    }

    sort(g, g+G, CompareGraze);

    int count = 0;
    for (int j = 0; j < N; j ++) {
	int pos = findPos(a[j].t);
	bool innocent = false;
        for (int k = pos -1; k <= pos; k++ ) {
	    if (k >= 0 &&  k < G) {
	 	innocent |= !reachable(a[j], g[k]);
	    }
	}       
	if (innocent) count ++; 
    }
    cout << count << endl;
}


