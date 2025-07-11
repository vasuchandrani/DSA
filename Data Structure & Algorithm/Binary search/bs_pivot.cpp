//find pivat element from sorted rotated arry by binary search

#include<iostream>
using namespace std;

int pivotElement(int arr[]){
    int s =0;
    int e=sizeof(arr)-1;
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

int main(){
    int arr[]= {8,10,17,1,3,5};

    cout<<"Index of pivot is "<<pivotElement(arr)<<endl;
}
