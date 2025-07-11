// max heap
// heapify fn / arry to heap 
// 1 base index

#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i) {
    
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if (left < n && arr[largest] < arr[left]) {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}


int main () {
    
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i=n/2; i>0; i--) {
        //heap banao
        heapify(arr, n, i);
    }

    cout<<"arry after heapify"<<endl;

    for(int i=1; i<=n; i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}


// parent node index = i/2
// leftChild index = 2*i 
// rightChild index = 2*i +1
// leaf node indeies = (n/2 + 1) to n