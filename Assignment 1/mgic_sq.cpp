#include <iostream>
using namespace std;

/*
Rule 1: 
1 is always stored at position (i,j)= (n/2, n-1)
Rule 2 :
next number position should be (i,j)= (i-1, j+1)
Rule 3:
if i=-1 then i=n-1
Rule 4 :
if j=n then j=0
Rule 5 :
if (i,j)==(-1,n) the (i,j)==(0,n-2)
Rule 6 :
if position is occupied then i=i+1, j=j-2
*/

int main(){

    int n=3;

    int magic_sq[n][n]={{0,0,0},
                        {0,0,0},
                        {0,0,0},
                        };
 
    int i=n/2;
    int j=n-1;


    for (int num=1; num<=n*n; num++){

        magic_sq[i][j]=num;


        i=i-1;
        j=j+1;

        if(i==-1 && j==n){
            i=0;
            j=n-2;
        }
        if(i<0 ){
            i=n-1;
        }
        if(j==n){
            j=0;
        }
        if(magic_sq[i][j]!=0){
            i=i+1;
            j=j-2;
        }

    }

    cout<<"Magic Sqaure :"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<magic_sq[i][j]<<" ";
        }
        cout<<endl;
    }
    
  
}