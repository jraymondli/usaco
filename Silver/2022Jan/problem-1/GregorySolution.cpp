#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
using namespace std;

// https://github.com/DaChosens1/C-UsacoWork/blob/master/2022/January/Silver/Problem%201/problem_1_new.cpp

int N;
pair<long long, long long> cow_pairs[10];

long long down(long long start, long long amount){//returns the value from the start given D
    long long end=start;
    for (long long i = 0; i < amount; i++){
        if (end%2==0) end/=2;
        else if (end!=1) end++;
        else return -1;
    }
    return end;
}

long long up(long long end, long long amount){//returns the value to get to the end given M
    long long start=end;
    for (long long i = 0; i < amount; i++){
        if (start%2==0) start/=2;
        else start--;
    }
    return start;
}

int main() {
	cin >> N;
    for (int i = 0; i < N; i++){
        cin >> cow_pairs[i].first >> cow_pairs[i].second;
    }
    for (int i = 0; i < N; i++){
        // cout << cow_pairs[i].first << " " << cow_pairs[i].second << "\n";
        long long sub_answer = INT32_MAX;
        for (int j = 0; down(cow_pairs[i].first, j)>0; j++){
            for (int k = 0; up(cow_pairs[i].second, k)>=1; k++) {
                // cout << j << " " << k << " " << up(cow_pairs[i].second, k) << "\n";
                if (down(cow_pairs[i].first, j)<=up(cow_pairs[i].second, k)){
                    sub_answer = min(sub_answer, j+k+up(cow_pairs[i].second, k)-down(cow_pairs[i].first, j));
                    // cout << "test\n";
                }
                // if (k==0 and j==0) cout << up(cow_pairs[i].second, k) << " " << down(cow_pairs[i].first, j) << "\n";
            }
        }
        cout << sub_answer << "\n";
    }
}


