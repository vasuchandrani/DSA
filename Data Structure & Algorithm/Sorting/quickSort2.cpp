// My Quick Sort - with Traversal

#include<iostream>
using namespace std;

void quickSort(int arr[], int s, int e, int n) {

    if (s >= e) {
        return;
    }
    int pivot = arr[s];
    int i = s + 1;
    int j = e;
    while (i <= j) {

        while (arr[i] < pivot) {
            i++;
        } 
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i++],arr[j--]);
        }
    }   

    swap(arr[s],arr[j]);
    
    // for print every-Traversal
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    // call recursion
    quickSort(arr,s,j-1,n);
    quickSort(arr,j+1,e,n);

}

int main() {
    int arr[] = {19,45,12,14,88,11};
    int n=sizeof(arr)/sizeof(arr[0]);

    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;
    cout<<"Traversals:"<<endl;

    quickSort(arr,0,n-1,n);
    

    cout<<"Sorted Array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}



// without print Traversal

#include<iostream>
using namespace std;

void quickSort(int arr[], int s, int e) {

    // base condition
    if (s >= e) {
        return;
    }

    int pivot = arr[s];
    int i = s + 1;
    int j = e;

    while (i <= j) {
        
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[s]);

    // call recursion 
    quickSort(arr,s,j-1);
    quickSort(arr,j+1,e);
}

int main () {
    int arr[] = {88,45,19,14,12,11};
    int n=sizeof(arr)/sizeof(arr[0]);

    quickSort(arr,0,n-1);

    cout<<"Sorted Array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}