// Bubble sort

#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int> &arr, int n){
    for(int i=0;i<n-1;i++){
        bool swapped =false;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped =true;
            }
        }
        if(swapped==false){
            break;
        }
    }
}

int main(){
    int n;
    cout<<"number of element: "<<endl;
    cin>>n;
    cout<<"enter elements: "<<endl;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }

    bubbleSort(arr,n);
    cout<<"After sorting: "<<endl;
    for(int i=0;i<n;i++){
        cout<<" "<<arr[i];
    }
    return 0;

}