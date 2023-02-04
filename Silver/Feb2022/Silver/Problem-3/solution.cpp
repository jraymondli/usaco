#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <tuple>
#include <list>
#include <stack>
#include <queue>
#include <deque>

#include <iterator>

using namespace std;

int c;
int M, N, K;
int f[10000];
int e[100000];

void printq(deque<int> dq) {
    cout << "Q:";
    while (dq.size() > 0) {
        cout << dq.front();
        dq.pop_front();
    }
    cout << endl;
}

void solve(int M, int N, int K)
{
    deque<int> emq;
    stack<int> ems;

    int e_nxt_idx = 0;

    for (int ifs = 0; ifs <= M - K; ifs ++) {
	auto ife = ifs + K - 1;
	for (int j = 0; j < emq.size(); j++) {
	    auto q_item = emq.front();
	    emq.pop_front();
	    if ( q_item < (ifs +1) || q_item > (ife +1) ) 
		emq.push_back(q_item);
	}

        while (ems.size() > 0 && emq.size() < K) {
            auto top = ems.top();
            ems.pop();
	    if (top > (ife +1) || top < (ifs +1)) {
		emq.push_front(top);
	    }
	}

	int last_mark = e_nxt_idx;
	for (int j = N - 1; j >= e_nxt_idx; j --) {
	    if (e[j] >= (ifs + 1) && e[j] <= (ife +1)) {
	        last_mark = j + 1;
		// cout << "last mark" << last_mark << endl;
		break;
	    } 
        }

        while (e_nxt_idx < last_mark) {
	   if (e[e_nxt_idx] < (ifs +1)  || e[e_nxt_idx] > (ife+1)) {
		emq.push_back(e[e_nxt_idx]);
		if (emq.size() > K) {
		    auto front = emq.front();
		    ems.push(front);
		    emq.pop_front(); 
		}
	   }
	   e_nxt_idx ++;	
	}
	// printq(emq);
    }

    while (ems.size() > 0 && emq.size() < K) {

	auto top = ems.top();
        ems.pop();	
	if (top < (M - K)) {
	    cout << "NO" << endl;
	    return; 
	}
    }

    if (emq.size() > 0 ) 
        cout << "NO";
    else
        cout << "YES";
    cout << endl;

}

int main()
{
    for (int i = 0; i < 10000; i ++)
	f[i] = i +1;
 
    cin >> c;
    for (int i = 0; i < c; i ++) {
	cin >> M >> N >> K;
	for(int j = 0; j < N; j ++) {
	    cin >> e[j];
	} 
	solve(M, N, K);
    }

}


