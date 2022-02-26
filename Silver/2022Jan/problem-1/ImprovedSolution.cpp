#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
using namespace std;

// https://github.com/DaChosens1/C-UsacoWork/blob/master/2022/January/Silver/Problem%201/problem_1_new.cpp

int N;
pair<long long, long long> cow_pairs[10];

//@returns the value reached 
long long down(long long start, long long steps){
    long long end=start;
    for (long long i = 0; i < steps; i++){
        if (end %2 ==0) end/=2;
        else if (end!=1) end++;
        else return -1;
    }
    return end;
}

//returns the value to start from
long long up(long long end, long long steps){
    long long start=end;
    for (long long i = 0; i < steps; i++){
        if (start%2 == 0) start /= 2;
        else start--;
    }
    return start;
}

// The optimal solution can always come in 3 phases
// s1: going down interleaved with adding 1's
// s2: adding several 1's
// s3: going up interleaved with adding 1's
int main() {
	cin >> N;
    for (int i = 0; i < N; i++){
        cin >> cow_pairs[i].first >> cow_pairs[i].second;
    }
    for (int i = 0; i < N; i++){
        // cout << cow_pairs[i].first << " " << cow_pairs[i].second << "\n";
        long long sub_answer = INT32_MAX;
        for (int s1 = 0; down(cow_pairs[i].first, s1)>0; s1++){
            for (int s3 = 0; up(cow_pairs[i].second, s3)>=1; s3++) {
                if (down(cow_pairs[i].first, s1)<=up(cow_pairs[i].second, s3)){
		    long long s2 = up(cow_pairs[i].second, s3) - down(cow_pairs[i].first, s1);
		    sub_answer = min(sub_answer, s1 + s2 + s3);
                }
            }
        }
        cout << sub_answer << "\n";
    }
}


