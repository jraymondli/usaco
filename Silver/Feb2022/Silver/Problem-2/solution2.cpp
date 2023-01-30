#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <tuple>
#include <queue>

/*
 * using map to try to reduce the memory usage and speed up
 * this does not work at all
 */

using namespace std;

int N, xg, yg;
int step[40][2];
int result[41];
map<tuple<int, int, int>, int> moves;
queue<tuple<int, int, int, int> > updates;

int main() 
{
   cin >> N;
   cin >> xg >> yg;
   for (int i = 0; i < N; i ++) {
       cin >> step[i][0] >> step[i][1];
   }

   // cout << N << << xg << yg << endl;
   /* for (int i = 0; i < N; i ++) {
       cout << step[i][0] << "," << step[i][1] << endl;
   }
   */

   moves[make_tuple(0, 0, 0)] = 1;
   for (int i = 0; i < N; i ++) {
	for (auto it = moves.begin(); it != moves.end(); it++) {
	    auto tp = it->first;
	    updates.push( make_tuple(get<0>(tp) + step[i][0], 
				     get<1>(tp) + step[i][0],
				     get<2>(tp) + 1, it->second));
	}
	while (updates.size()) {
	    auto update = updates.front();
            updates.pop();
	    moves[ make_tuple( get<0>(update), get<1>(update), get<2>(update))] += get<3>(update);
	}
   }

   for (auto it = moves.begin(); it != moves.end(); it++) {
	auto tp = it->first;
        if (get<0>(tp) == xg && get<1>(tp) == yg) {
	    result[get<2>(tp)] += it->second;
	}
   }

   for (int k = 1; k <= N; k ++) {
	cout << result[k] << endl;
   } 
   
}




