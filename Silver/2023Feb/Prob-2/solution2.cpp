
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

struct Graze {
   int x;
   int y;
   int t;
};

struct Alibi {
   int x;
   int y;
   int t;
};

struct Graze g[100001];
struct Alibi a[100001];

int G;
int N;

bool CompareGraze(const Graze &g1, const Graze &g2) 
{
    return g1.t < g2.t;
}

void printGraze()
{
    for (int i = 0; i < G; i ++) {
	cout << g[i].t << endl;
    }
}

bool reachable(struct Graze g1, struct Graze g2) {
     int dist = abs(g1.x - g2.x) + abs(g1.y - g2.y);
     return (dist <= abs(g1.t - g2.t));
    
}

bool reachable(struct Graze g, struct Alibi a) {
    int dist = abs(g.x - a.x) + abs(g.y - a.y);
    return (dist <= abs(g.t - a.t));
}

int findPos(int t) {
   if (t < g[0].t) return -1;

   int l = 0, h = G - 1;
   while (l < h) {
     int mid = (l + h) / 2;
     if (g[mid].t == t) return mid;

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
    for (int i = 0; i < (G-1); i ++) {
        if (! reachable(g[i], g[i+1])) {
	    cout << N << endl;   
	    return 0;
	} 
    }

    int count = 0;
    for (int j = 0; j < N; j ++) {
        if (a[j].t > g[G-1].t) {
	    if (! reachable(g[G-1], a[j])) {
	        count ++;
	    } 
	    continue;
	}
	if (a[j].t < g[0].t) {
            if (! reachable(g[0], a[j])) {
                count ++;
            }
            continue;
        }
	int pos = findPos(a[j].t);
        if (g[pos].t == a[j].t) 
	    continue;
 	if ( ! reachable(g[pos-1], a[j]) || ! reachable(g[pos], a[j])) {
	    count ++;
	}
    }
    cout << count << endl;
}


