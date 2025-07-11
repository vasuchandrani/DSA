//peak index in mountain array by binary search

#include<iostream>
using namespace std; 

int peakValue(int arr[],int size){

    int s =0;
    int  e =size-1;

    int mid = s+(e-s)/2;

    while(s<e){
        if(arr[mid] < arr[mid+1]){
            s =mid+1;
        }
        else{
            e =mid;
        }
        mid = s+(e-s)/2;
    }
    return s;
}

int main(){
    int arr[7] ={1,3,4,6,9,3,2};

    int index = peakValue(arr, 7);
    
    //cout<<"index of peak value element is "<<index<<endl;
}