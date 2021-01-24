#include <iostream>
#include <fstream>
using namespace std;

char pic[8][8][11];
int N, K;
ifstream fin("piece.in");


void readPiece(int k) 
{
   for(int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
	    fin >> pic[i][j][k];
        }
   }

}

void printOut()
{
    for (int k = 0; k < K + 1; k ++) {
        for(int i = 0; i < N; i ++) {
          for (int j = 0; j < N; j ++) {
	     cout << pic[i][j][k] ;
          }
          cout << endl;
        }
    }

}

struct range {
    int xmin;
    int xmax;
    int ymin;
    int ymax;
};

void getRange(int k, struct range *r)
{
     r->xmin = 0;
     r->xmax = 0;
     r->ymin = 0;
     r->ymax = 0;

     int xmin = N;
     int xmax = 0;
     int ymin = N;
     int ymax = 0;

     for (int m = 0; m < N; m++) {
         for (int n = 0; n < N; n ++) {
	     if (pic[m][n][k] == '#')  {
                  if (m < xmin) xmin = m;
                  if (m > xmax) xmax = m;
                  if (n < ymin) ymin = n; 
                  if (n > ymax) ymax = n;
             } 
         }

     }

     r->xmin = - xmin;
     r->xmax = N - xmax;

     r->ymin = - ymin;
     r->ymax = N - ymax;
 
}

void getImage(int i, int k, int l, char image[][8]) 
{
    for (int m = 0; m < N; m ++) {
        for (int n = 0; n < N; n ++) {
            image[m][n] = '.';
        }
    } 

    for (int m = 0; m < N; m ++) {
        for (int n = 0; n < N; n ++) {
            if (pic[m][n][i] == '#') {
               image[m+k][n+l] = '#';
            }
        }
    }
}

int twoImageFit(char image1[][8], char image2[][8]) 
{
    for (int m = 0; m < N; m ++) {
        for (int n = 0; n < N; n ++) {
	    if ((image1[m][n] == '#') && (image2[m][n] == '#'))
		return 0;
            if ( (pic[m][n][0] == '#') && (image1[m][n] == '.') && (image2[m][n] == '.'))
		return 0;
        }
    }

    return 1;
}


int imageMatch(int i, int j) 
{
    struct range r1, r2;
    getRange(i, &r1);
    getRange(j, &r2);

    char image1[8][8];
    char image2[8][8];

    for (int k = r1.xmin; k < r1.xmax; k++) {

	for (int l = r1.ymin; l < r1.ymax; l ++) {

            getImage(i, k, l, image1); 
           
	    for (int m = r2.xmin; m < r2.xmax; m ++) {

		for (int n = r2.ymin; n < r2.ymax; n ++) {

		    getImage(j, m, n, image2);
		    if (twoImageFit(image1, image2) )
		        return 1;
		}
            }

 
        }
    }


    return 0;
}


int main()
{
    fin >> N >> K;
    cout << "N:" << N << endl << "K:" << K << endl;

    for (int k = 0; k < K + 1; k ++) {
   	readPiece(k); 
    }

    for (int i = 1; i < (K + 1); i ++) {
	for (int j = i + 1; j < (K + 1); j ++) {

	    if (imageMatch(i, j)) {
            	cout << i << " " << j << endl;
            }
 
        }

    }

    printOut();
    return 0;
}
