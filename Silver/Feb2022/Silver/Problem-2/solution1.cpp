#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <tuple>

/*
 * a straightforward solution
 */

using namespace std;

int N, xg, yg;
int step[40][2];
vector<tuple <int, int, int> > moves;
int result[41];

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

   moves.push_back(make_tuple(0, 0, 0));
   for (int i = 0; i < N; i ++) {
        int len = moves.size();
	for (int j = 0; j < len; j ++) {
	    auto move = moves[j];
	    moves.push_back(make_tuple(get<0>(move) + 1, get<1>(move) + step[i][0], get<2>(move) + step[i][1]));
        }
   }


   for (int j = 0; j < moves.size(); j ++) {
       if (get<1>(moves[j]) == xg && get<2>(moves[j]) == yg) {
   	   result[get<0>(moves[j])] ++;
       }
   } 

   for (int k = 1; k <= N; k ++) {
	cout << result[k] << endl;
   } 
   
}




