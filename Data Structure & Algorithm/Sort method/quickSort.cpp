// Love Babbar Quick Sort

#include <bits/stdc++.h>
#include<vector>
using namespace std;

int partition(int a[],int s,int e){
    
    int pivot = a[s];
    int count = 0;
    
    for(int i=s+1; i<=e; i++){  // 10, 7, 8, 9, 1, 5  
        if(a[i]<pivot){
            count++;
        }
    }
    int pivotIndex = s + count;
    swap(a[pivotIndex],a[s]);   // 5, 7, 8, 9, 1, 10

    //left aur right vale part ko dekhte hai
    int i = s, j = e;
    while(i<pivotIndex && j>pivotIndex){

        while(a[i]<pivot){
            i++;
        }
        while(a[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(a[i++],a[j--]);
        }
    }
    return pivotIndex;
}
void quickSort(int arr[],int s,int e)
{

    if(s>=e){
        return;
    }
    else{
        //partition karenge
        int p = partition(arr,s,e);
        //left vala part sort karenge
        quickSort(arr,s,p-1);
        //right vala part sort kaenge 
        quickSort(arr,p+1,e);
    }
}
             
 
int main() {
    int arr[] = {10,7,8,9,1,5};
    int n=sizeof(arr)/sizeof(arr[0]);

    quickSort(arr,0,n-1);
    

    cout<<"Sorted Array"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

/*
class Solution {
public:
    vector<int> sortArray(vector<int>x& nums){
        int s = 0;
        int e = nums.size() - 1;

    }

    void quickSort(int arr[],int s,int e){

        if(s>=e){
            return;
        }
        else{
            //partition karenge
            int p = partition(arr,s,e);
            //left vala part sort karenge
            quickSort(arr,s,p-1);
            //right vala part sort kaenge 
            quickSort(arr,p+1,e);
        }
    }
};


*/