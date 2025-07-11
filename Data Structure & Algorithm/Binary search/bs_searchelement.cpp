//search element by binary search
//Time complexity of binarysearch is log(n);

#include<iostream>
using namespace std;

int binarysearch(int arr[],int size, int key){
    int start =0;
    int end =size-1;

    int mid = start + (end-start)/2;

    while(start<=end){

        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]>key){
            end = mid-1;
        }
        if(arr[mid]<key){
            start = mid+1;
        }

        mid = start + (end-start)/2;        
    }

    return -1;
}

int main(){

    int even[6] ={2,3,6,8,9,10};
    int odd[5] ={1,3,6,9,11};

    int evenIndex = binarysearch(even, 6 ,12);
    int oddIndex = binarysearch(odd, 5 ,12);

    cout<<"index of 8 is "<<evenIndex<<endl;
    cout<<"index of 9 is "<<oddIndex<<endl;
    
    return 0;
}