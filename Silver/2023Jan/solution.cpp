#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <tuple>
#include <set>
#include <queue>
#include <deque>

#include <iterator>

using namespace std;

int c;
string s1, s2;
vector<char> a1;
vector<char> a2;
map<char, bool> visited;
map<char, set<char> > rel;

bool dfs(char c)
{  
    auto nxt = rel[c];
    if (nxt.size() == 0) return false;

    auto nxtChar = *nxt.begin();

    if (nxtChar == c) return false;
    if (visited[nxtChar]) return true;
    visited[nxtChar] = true;
    return dfs(nxtChar);
}  

void solve() {
    // cout << s1 << ";" << s2 << endl;
    vector<char> a1(s1.begin(), s1.end());
    vector<char> a2(s2.begin(), s2.end()); 
    if (a1.size() != a2.size()) {
	cout << -1 << endl;
	return;
    }

    int N = a1.size();

    rel.clear();
    visited.clear();

    for (int i = 0; i < N; i++) {
	auto c1 = s1[i];
	auto c2 = s2[i];

	rel[c1].insert(c2);
    }

    int count = 0;
    for (auto it = rel.begin(); it != rel.end(); it ++) {
	if (it->second.size() > 1) {
	    cout << -1 << endl;
   	    return;
   	}

	if (it->first != *(it->second.begin()) ) 
	    count += 1;
	visited[it->first] = false;
    }

    // identify loop
    for (auto it = visited.begin(); it != visited.end(); it ++) {
	if (it->second) continue;
	if (dfs(it->first)) count ++;
    }
 
    cout << count << endl;
}


int main() {

    cin >> c;
    for (int i = 0; i < c; i ++) {
	cin >> s1;
	cin >> s2;	
	solve();
    }


}


