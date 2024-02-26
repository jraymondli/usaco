#include <iostream>

using namespace std;

const int MAXM = 300002;
int N, M, K;
int T;
int a[MAXM][4];
int mx[MAXM][2];
long long mop[MAXM]; // max odd prefix, when odd is played 
long long mmp[MAXM]; // min max prefix]
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
	mx[i][0] = meven;
	mx[i][1] = modd;
    }
}


// calculate max odd and max max
void calc() {

    long long mo_acc;
    long long min_max_acc; 
    for (int i=0; i < M; i++) {
	int meven = mx[i][0];
	int modd = mx[i][1];

 	mo_acc +=  modd;
 	mop[i+1] = mo_acc;

	min_max_acc += min(meven, modd);
	mmp[i+1] = min_max_acc;			
        
    }
}

// first odd between 0 .. M-1
int find_first_odd(int start, long long total) {

    int l = start;
    int r = M-1;
    int m;

    if ( (mmp[M] - mmp[start]) >= total) 
	return -1;

    if ( (mop[M] - mop[start]) < total)
	return M;
    
    while(l < (r+1) ) {

        m = (l + r) /2;

	long long acc = mop[m+1] - mop[start];
	int meven = mx[m+1][0];
	acc += meven;	
	acc += mmp[M] - mmp[m+1];
	if (acc >= total)  r = m;
        else l = m;
    }

    return r; 

}

void find_es(){
   
    int start = 0;
    long long total = N; 
    while (start < M )  {
	int ri = find_first_odd(start, total);
	if (ri == -1) { cout << -1 << endl; exit; }	
	if (ri == M) return;
	o[ri] = 1;
	total -= (mop[ri] - mop[start]);
	total -= mx[ri][1]; 
	start = ri + 1;		
    }

}

void write_output() 
{
    for(int i=0; i<M; i++) {
	cout << (o[i] == 1)? "ODD" : "EVEN";
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


 

