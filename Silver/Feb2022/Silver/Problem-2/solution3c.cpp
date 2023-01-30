#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <map>

/*
 * using map to try to reduce the memory usage and speed up
 * this works on 6 of the test cases
 */

using namespace std;

int N, xg, yg;
int fstep[40][2];
int rstep[20][2];
int result[41];
map<int, map<int, map<int, int> > > fmoves;
map<int, map<int, map<int, int> > > rmoves;

queue<tuple<int, int, int, int> > updates;

void traverse(map<int, map<int, map<int, int> > > &moves, int start_x, int start_y, int end_x, int end_y, int N, int step[][2]) 
{

   moves[start_x][start_y][0] = 1;
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
                if (it1->first == end_x && it2->first == end_y)
                    result[it3->first] += it3->second;
            }
       }
   }
}

int main() 
{
   cin >> N;
   cin >> xg >> yg;
   for (int i = 0; i < N; i ++) {
       cin >> fstep[i][0] >> fstep[i][1];
   }

   traverse(fmoves, 0, 0, xg, yg, min(N, 20), fstep);
   if (N > 20) {
	for (int i = 0; i < (N-20); i ++) {
	    rstep[i][0] = - fstep[N-i-1][0];
	    rstep[i][1] = - fstep[N-i-1][1];
 	}
	traverse(rmoves, xg, yg, 0, 0, N - 20, rstep);
   }

   for (auto it1 = fmoves.begin(); it1 != fmoves.end(); it1 ++) {
           for(auto it2 = it1->second.begin(); it2 != it1->second.end(); it2 ++) {
                for (auto it3 = it2->second.begin(); it3 != it2->second.end(); it3 ++) {
		    if (rmoves.find(it1->first) != rmoves.end() && rmoves[it1->first].find(it2->first) != rmoves[it1->first].end()) {
			auto bmap = rmoves[it1->first][it2->first];
			for (auto it3b = bmap.begin(); it3b != bmap.end(); it3b ++) {
			    if (it3->first != 0 and it3b->first != 0) 
			       result[it3->first + it3b->first] += it3->second * it3b->second;
			}
		    }
                }
           }
       }


   for (int k = 1; k <= N; k ++) {
	cout << result[k] << endl;
   } 
   
}




