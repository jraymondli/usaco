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
int seg[100001];

int main()
{
   cin >> N;

   for (int i = 0; i < N; i ++) {
	cin >> seg[i]; 
   }

   bool forward = true;
   int pos = 0;

   while (true) {

        if (pos == 0 && seg[0] == 0) break;

        cout << (forward? "R" : "L");
        seg[pos] --;

 	if (pos == (N-1) && forward) {
	    forward = false;
	} else if (pos == 0 && ! forward) {
	    forward = true;
        } else if (forward) {
	    if (seg[pos+1] < seg[pos]) {
		forward = false;
	    } else {
		pos ++;
	    } 
	} else {
	    if (seg[pos-1] < seg[pos]) {
		forward = true;
	    } else {
		pos --;
	    }
	}

   }

   cout << endl; 
}


