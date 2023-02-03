#include <bits/stdc++.h>
#include <iostream>

using namespace std;

using P = pair<long long, long long>;
P operator+(P a, P b) { return {a.first + b.first, a.second + b.second}; }
P operator-(P a, P b) { return {a.first - b.first, a.second - b.second}; }

void print(P p)
{
   cout << "{" << p.first << ", " << p.second << "}" << endl;
}

int main()
{
    P p1 = make_pair(1, 2);
    P p2 = make_pair(3, 4);

    cout << "p1 + p2: ";
    print(p1 + p2);   

    cout << "p1 - p2: ";
    print(p1 - p2);
 
}




