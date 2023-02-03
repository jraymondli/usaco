#include <bits/stdc++.h>
#include <iostream>

using namespace std;


void printVector(vector<int> &v) {
    for (auto &e : v) {
       cout << e << ";" ;
    }
    cout << endl;
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    printVector(v);

    reverse(v.begin(), v.end());
    printVector(v);

}


