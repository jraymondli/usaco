#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <tuple>
#include <list>
#include <iterator>
#include <type_traits>

using namespace std;

int bisect_right(int ar[], int n, int s)
{
    int l = 0, r = s, m;
    while (r>l){
        m = (l+r)/2;
        if (ar[m]<=n) {
            l=m+1;
        } else if (ar[m]>n) {
            r=m;
        }
    }
    return m+1;
}

int main()
{
   int ar[100];
   for (int i = 0; i < 100; i++) {
       ar [i] = i * 2;
   }
   cout << bisect_right(ar, -1, sizeof(ar)/sizeof(ar[0])) << endl;

}

