#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;
int main() {

srand(time(NULL));
int number =rand()%100;
int guess=-1;
int tryout=0;

while(guess!= number && tryout< 8){
    cout<<"Please enter guess :";
    cin>>guess;
}

if(guess<number){
    cout<<"Too low"<<endl;
}

if(guess >number){
    cout<<"Too high"<<endl;
}

if(guess== number ){
    cout<<"You guessed corrct number !!!";
}
else{
     cout<<"Sorry the number incorrect !!!";
}
    return 0;
}
