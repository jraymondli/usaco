
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <tuple>
#include <list>
#include <iterator>

using namespace std;


void print(list<int> &lst) {
    for (auto &e : lst) {
       cout << e << ";" ;
    }
    cout << endl;
}


int main()
{
   list<int> l1;
   l1.push_back(1);

   l1.push_back(2);
   l1.push_back(2);
   l1.push_back(3);

   print(l1);
   l1.remove(2);
   print(l1);
}




