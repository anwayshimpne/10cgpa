#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int> &arr){
    int n=arr.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j=1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

//partition fun for Quick Sort
int partition(vector<int> &arr, int st, int end){
    int idx=st-1;
    int pivot=arr[end]; 
    
    for (int j=st; j<end; j++){
         if(arr[j]<=pivot){
            idx++;
            swap(arr[j],arr[idx]);
         }
    }
    
    idx++;
    swap(arr[end],arr[idx]);
    return idx;
}

void quickSort(vector<int> &arr, int st, int end){
    if(st < end){
            int pivIdx= partition(arr,st ,end);
            quickSort(arr, st, pivIdx-1);   //left side call
            quickSort(arr, pivIdx+1,end); 
    }

}



int main(){

    vector<int> arr={5,2,6,4,1,3};
    quickSort(arr, 0,(arr.size())-1 );

    bubbleSort(arr);
    

    for(int val :arr){
        cout<<val<<" ";
    }

    return 0;
}