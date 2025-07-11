// max heap
// insert and delete Root in heap tree
// 1 base index

#include<bits/stdc++.h>
using namespace std;

class heap {
public:
    int arr[100];
    int size;
     
    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {

        size++;
        int idx = size;
        arr[idx] = val;

        while (idx > 1) {
            int parent = idx / 2; 

            if (arr[idx] > arr[parent]) {
                swap(arr[idx], arr[parent]);
                idx = parent;
            }
            else {
                return;
            }
        }
    }

    void deleteRoot() {
        
        if (size == 0) {
            cout<<"nothing to delete"<<endl;
            return;
        }

        // 1-> last wale ko root bana do..
        arr[1] = arr[size];

        // 2-> last wale ko hata do..
        size--;

        // 3-> heap ko thik kro..
        int i = 1;
        while (i < size) {
            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;

            if (leftIndex < size  && arr[i] < arr[leftIndex]) {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] > arr[rightIndex]) {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else {
                return;
            }
        }
    }

    void print () {
        for (int i=1; i<=size; i++) {
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};


int main () {

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deleteRoot();
    cout<<"After delete Root"<<endl;
    h.print();

    return 0;  
}

// parent node index = i/2
// leftChild index = 2*i 
// rightChild index = 2*i +1
// leaf node indeies = (n/2 + 1) to n