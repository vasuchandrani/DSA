//find element from rotated sorted array using pivot

#include<iostream>
using namespace std;

int pivotElement(int arr[], int n){
    int s =0;
    int e=n-1;
    int mid =s+ (e-s)/2;

    while(s<e){
        if(arr[mid]>arr[0]){
            s =mid+1;
        }
        else{
            e =mid;
        }
        mid =s+ (e-s)/2;
    }
    return s;
}

int searchElement(int arr[], int start, int end, int target){
    int s =start;
    int e =end;
    int mid =s+ (e-s)/2;

    while(s<=e){
        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid]>target){
            e = mid-1;
        }
        if(arr[mid]<target){
            s = mid+1;
        }
        mid =s+ (e-s)/2;
    }
    return -1;
}


int main(){
    int arr[]= {8,10,17,1,3,5};

    int target;
    cin>>target;
    int pivot = pivotElement(arr, 6);
    
    if(arr[pivot]<= target && target <=arr[6-1]){
        cout<<"index number is "<<searchElement(arr, pivot, 6, target);
    }
    else{
        cout<<"index number is "<<searchElement(arr, 0, pivot, target);
    }
    

   
}
