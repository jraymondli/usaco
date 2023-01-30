#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <tuple>
#include <queue>

/*
 * using unordered_map to try to reduce the memory usage and speed up
 * this works on 6 of the test cases, same as using map
 */

using namespace std;

int N, xg, yg;
int step[40][2];
int result[41];
// unordered_map<tuple<int, int, int>, int> moves;
unordered_map<int, unordered_map<int, unordered_map<int, int> > > moves;

queue<tuple<int, int, int, int> > updates;

int main() 
{
   cin >> N;
   cin >> xg >> yg;
   for (int i = 0; i < N; i ++) {
       cin >> step[i][0] >> step[i][1];
   }

   moves[0][0][0] = 1;
   for (int i = 0; i < N; i ++) {

       for (auto it1 = moves.begin(); it1 != moves.end(); it1 ++) {
	   for(auto it2 = it1->second.begin(); it2 != it1->second.end(); it2 ++) {
		for (auto it3 = it2->second.begin(); it3 != it2->second.end(); it3 ++) {
		    updates.push(make_tuple(it1->first + step[i][0], it2->first + step[i][1], it3->first + 1, it3->second));
		}
	   }
       }

       while (updates.size()) {
            auto update = updates.front();
            updates.pop();
            moves[ get<0>(update)] [get<1>(update)] [get<2>(update)] += get<3>(update);
       } 
   }

   for (auto it1 = moves.begin(); it1 != moves.end(); it1 ++) {
       for(auto it2 = it1->second.begin(); it2 != it1->second.end(); it2 ++) {
            for (auto it3 = it2->second.begin(); it3 != it2->second.end(); it3 ++) {
		if (it1->first == xg && it2->first == yg) 
		    result[it3->first] += it3->second;
       	    }
       }
   }

   for (int k = 1; k <= N; k ++) {
	cout << result[k] << endl;
   } 
   
}




