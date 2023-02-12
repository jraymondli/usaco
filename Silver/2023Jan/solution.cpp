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
map<char, bool> loop_visited;
map<char, set<char> > rel;
map<char, int> loop_idx_map;

bool dfs(char c, char root)
{ 
    loop_visited[c] = true; 

    auto nxt = rel[c];
    if (nxt.size() == 0) return false;

    auto nxtChar = *nxt.begin();

    if (nxtChar == c) return false;
    if (nxtChar == root) return true;
    if (loop_visited[nxtChar]) return false;

    return dfs(nxtChar, root);
}  

int set_loop_idx(char c, int loop_idx)
{
    loop_idx_map[c] =  loop_idx;

    auto nxt = rel[c];
    auto nxtChar = *nxt.begin();

    if (loop_idx_map[nxtChar] == loop_idx)
	return 0;

    return 1 + set_loop_idx(nxtChar, loop_idx);

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
    loop_idx_map.clear();

    for (int i = 0; i < N; i++) {
	auto c1 = a1[i];
	auto c2 = a2[i];

	rel[c1].insert(c2);
    }

    int count = 0;
    for (auto it = rel.begin(); it != rel.end(); it ++) {
	if (it->second.size() != 1) {
	    cout << -1 << endl;
   	    return;
   	}

	if (it->first != *(it->second.begin()) ) 
	    count += 1;
	visited[it->first] = false;
    }

    // cout << endl << "rules:" << rel.size() << endl;

    // cout << count << endl;
    // identify loop
    int loop_idx = 0;
    for (auto it = visited.begin(); it != visited.end(); it ++) {
	if (it->second) continue;
	loop_visited.clear();
	if (dfs(it->first, it->first)) {
	    count ++;
	    loop_idx ++;
 	    set_loop_idx(it->first, loop_idx) ;
        }
	for (auto it2 = loop_visited.begin(); it2 != loop_visited.end(); it2++) {
	    visited[it2->first] = it2->second;
	}
    }

    set<int> loopsWithTails;

    for (auto it = rel.begin(); it != rel.end(); it ++) {
	if (loop_idx_map[it->first]) continue;

	auto nxtChar = *(it->second.begin());
	if (loop_idx_map[nxtChar]) {
	    loopsWithTails.insert(loop_idx_map[nxtChar]);
        }
    }
    // cout << "loops:" << loop_idx << endl;
    // cout << "size:" << loopsWithTails.size() << endl; 
    if (rel.size() == 52 && loop_idx > loopsWithTails.size() )  {
	cout << -1 << endl;
	return;
    }
 
    count -= loopsWithTails.size() ;
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


