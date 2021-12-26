#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int K, M, N;
vector<pair <int, int> > tastyPatches;  /* 0 4
                                           4 6
                                           8 10
                                           10 8
                                           12 12
                                           13 14
                                        */
vector<int> NJcows;//2 3 5 7 11
vector< vector<pair <int, int> > > patches;
vector<pair <int, int> > intervals;
vector<pair <int, int> > cur_interval;
vector<int > finals;

int main() {
    ifstream fin("input.in");
    ofstream fout("output.out");
    fin >> K >> M >> N;
    cout << K << " " << M  << " " << N << "\n";
    for (int i = 0; i < K; i++){
        int temp1, temp2;
        fin >> temp1 >> temp2;
        cout << temp1 << " " << temp2 << "\n";
        tastyPatches.push_back(make_pair(temp1, temp2));
    }
    NJcows.push_back(0);
    for (int i = 0; i < M; i++){
        int temp;
        fin >> temp;
        cout << temp << "\n";
        NJcows.push_back(temp);
    }
    NJcows.push_back(1e9+1);

    int cow_interval=0, tastyPatch=0;
    cout << "\n\n";
    while (tastyPatch < K+1){
        cout << NJcows[cow_interval] << " " << tastyPatches[tastyPatch].first << " " << tastyPatches[tastyPatch].second << " " << NJcows[cow_interval+1] << "\n";

        if (NJcows[cow_interval]<=tastyPatches[tastyPatch].first and tastyPatches[tastyPatch].first<=NJcows[cow_interval+1]){
            cur_interval.push_back(tastyPatches[tastyPatch]);
            tastyPatch++;
        }
        else {
            patches.push_back(cur_interval);
            intervals.push_back(make_pair(NJcows[cow_interval], NJcows[cow_interval+1]));
            cow_interval++;
            cur_interval.clear();
        }
    }
    //intervals[i]: (front Nihoj cow) ; patches: vector of tasty patches ; patches[i][_]: (location, tasty)
    cout << "\n" << intervals.size() << "\n";
    for (int i = 0; i < intervals.size(); i++){
        // cout << intervals[i].first << " " << intervals[i].second << "\n";
        if (patches[i].size()==1) {
            finals.push_back(patches[i][0].second);
            cout << patches[i][0].second <<"\n";
        }
        else if ((intervals[i].first==0 or intervals[i].second==(1e9+1))){
            int total=0;
            for (int j = 0; j < patches[i].size(); j++){
                total+=patches[i][j].second;
            }
            finals.push_back(total);
            cout << total << "\n";
        }
        else if (patches[i].size()!=0){
            int total1 = 0, total2 = 0;
            for (int j = 0; j < cur_interval.size(); j++){
                if (patches[i][j].first < (patches[i][0].first*2-intervals[i].first+intervals[i].second)/2) total1+=patches[i][j].second;
                if (patches[i][j].first > (patches[i][0].first*2-intervals[i].first+intervals[i].second)/2) total2+=patches[i][j].second;
            }
            finals.push_back(total1);
            finals.push_back(total2);
            cout << total1 << " " << total2 << "\n";
        }
        cow_interval++;
    }
    
    long long ans=0;
    sort(finals.begin(), finals.end());
    for (int i = 0; i < N; i++) {
        ans += finals[finals.size()-i-1];
        cout<<finals[finals.size()-i-1] << "\n";
    }
    fout << ans << "\n";
}
