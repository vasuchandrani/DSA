// Insertion sort

#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int> &arr,int n){

    for(int i=1;i<n;i++){
        
        int temp = arr[i];
        int j = i - 1;
        while(j>=0){
            
            if(arr[j]>temp){
                //shift
                arr[j+1] = arr[j];
            }
            else{
                //ruk jao
                break;
            }   
            j--;
        }
        arr[j+1] = temp;
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

    insertionSort(arr,n);
    cout<<"After sorting: "<<endl;
    for(int i=0;i<n;i++){
        cout<<" "<<arr[i];
    }
    
    return 0;
}