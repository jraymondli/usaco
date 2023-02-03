#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << " queue front:" << q.front() << endl;

    q.pop();


    cout << " queue front:" << q.front() << endl;

    q.pop();

    cout << " queue front:" << q.front() << endl;

    q.pop();

}



