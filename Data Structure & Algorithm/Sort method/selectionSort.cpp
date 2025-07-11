//don't work
//incomplete

#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int> *arr, int n){

    for(int i=0;i<(n-1);i++){
        int minIndex =i;
        for(int j=i+1;j<n;j++){
            if(*(arr+i)<*(arr+minIndex)){
                minIndex =j;
            }
        }
        swap(*(arr+i),*(arr+minIndex));
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

    selectionSort(&arr,n);
    cout<<"After sorting: "<<endl;
    for(int i=0;i<n;i++){
        cout<<" "<<arr[i];
    }
    return 0;
}