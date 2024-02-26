#include <iostream>

using namespace std;

const int MAXM = 300002;
int N, M, K;
int T;
int a[MAXM][4];
int m[MAXM][2];
long long mop[MAXM];     // max odd prefix
long long minmaxp[MAXM]; // min max prefix]
int o[MAXM];

void get_inputs()
{
   cin >> N >> M >> K;

   for(int i=0; i<M; i++) {
	for(int j=0; j<K; j++) {
	    cin >> a[i][j];
	}
   }  
}

void get_max()
{
    for(int i=0; i<M; i++) {
	int meven = 0;
	int modd = 0;
        for(int j=0; j<K; j++) {
	    if(a[i][j] %2 == 0)
		meven = max(meven, a[i][j]);
	    else 
		modd = max(modd, a[i][j]);	
	}	
	m[i][0] = meven;
	m[i][1] = modd;
    }
}


// calculate max even and max max
void calc() {
 
    long long mo_acc;
    long long min_max_acc; 
    for (int i=0; i < M; i++) {
	int meven = m[i][0];
	int modd = m[i][1];

 	mo_acc +=  modd;
 	mop[i+1] = mo_acc;

	min_max_acc += min(meven, modd);
	minmaxp[i+1] = min_max_acc;			
        
    }
}

void find_first_odd(int start) {
}

void find_es(){
   
    int start = 0;

    while (start < ( M -1) )  {
    }

}

void write_output() 
{
    for(int i=0; i<M; i++) {
	cout << o[i]? "ODD" : "EVEN";
    }
    cout << endl;
}

void solve()
{
    get_inputs();
    get_max();
    calc();
    find_es();
    write_output();
}

int main() {
   cin >> T;
   for(int i=0; i<T; i++) {
	solve();
   }

   return 0;
}


 

