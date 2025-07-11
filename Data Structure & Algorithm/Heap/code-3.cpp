// max heap 
// heap sort
// 0 base index

#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i) {
    
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if (left <= n && arr[largest] < arr[left]) {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort (int arr[], int n) {

    int size = n;  

    while (size > 1) {

        // 1-> swap last and first (smallest and largest)
        swap(arr[1], arr[size]);

        // 2-> remove last ele
        size--;

        // 3-> rearrange the heap 
        heapify(arr, size, 1);  
        // you always rearrange the root of tree.. 
        // that's why we are passing i == 1.
    }
}

int main () {
        
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    // heap creation 
    for (int i=n/2; i>0; i--) {
        heapify(arr, n, i);
    }

    cout<<"arry after heapify"<<endl;
    for(int i=1; i<=n; i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;

    // heap sort 
    heapSort(arr, n);
    cout<<"Arry after sort"<<endl;
    for(int i=1; i<=n; i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;
    
}


/*

// max and min heap by STL
int main () {

    // max heap
    priority_queue<int> pq;

    //min heap 
    priority_queue<int, vector<int>, greater<int>> pq;

}

*/