#include<iostream>
using namespace std;

int BinarySearch(int arr[], int size, int target ){

    int low= 0;
    int high= size-1;

    while(low<=high){
        int mid =(low +high)/2;

        if(arr[mid]== target){
            return mid;
        }

        if(arr[mid]<target){
            low=mid+1;
        }

        if(arr[mid]> target){
            high=mid-1;
        }

    }
    return -1;
}

int main(){

    int arr[]= {10,15,18,20,25,30,40,50};
    int size= sizeof(arr)/ sizeof(arr[0]);
    int target =60;

    int result=BinarySearch(arr, size, target);
    
    
    if(result==-1){
        cout<<"Element not found ";
    }
    else{
        cout<<"Element "<<target<<" Found on position "<<result;
    }
    
    return 0;
}
