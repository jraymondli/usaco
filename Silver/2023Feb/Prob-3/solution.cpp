
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

int M, N;
int c[200001], d[200001], r[200001], s[200001], a[200001];
int et[200001];

list<int> adj[200001];
queue<int> q;

int main()
{
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
       cin >> c[i] >> r[i] >> d[i] >> s[i];
       // cout << "input received:" << c[i] << endl;
       adj[ c[i] ].push_back(i);	
    }

    for (int j=1; j <= N; j ++) {
	cin >> a[j];
	et[j] = -1;
    }

    et[1] = 0;
    q.push(1);

    while (! q.empty() ) {
	int curr = q.front();
        // cout << curr << endl;
	q.pop();

        auto nxtNodes = adj[curr];
        // cout << nxtNodes.size() << endl;
	for (auto it = nxtNodes.begin(); it != nxtNodes.end(); it++) {
	    // cout << * it << endl;
	    int fi = * it; // flight index
	
            int layover = a[curr];
	    if (curr == 1) layover = 0;

	    if ( (et[curr] + layover) <= r[fi]) {
		// taking the flight
                int next_airport = d[fi];
		int next_arrival = s[fi]; 
		if (et[next_airport] == -1 || next_arrival < et[next_airport] ) {
		    et[next_airport] = next_arrival;
		    q.push(next_airport);
		}

  	    }  
        }
    }
    for (int j = 1; j <=N; j ++ ) {
       cout << et[j] << endl; 
    }
  
}


