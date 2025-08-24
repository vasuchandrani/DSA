#include<bits/stdc++.h>
using namespace std;

void merge (vector<int> &arr, int low, int mid, int high) {

    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {

        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    } 

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // how???
    for (int i=low ; i<=high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    
    if (low == high)    return;
    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main () {
    vector<int> arr = {4,3,5,7,9,1,6};

    mergeSort(arr, 0, 7);

    cout<<"Sorted arry"<<endl;
    for (auto i : arr) {
        cout<<i<<" ";
    }cout<<endl;
}


// #include<iostream>
// #include<vector>
// using namespace std;

// void merge(vector<int> &arr, int s, int mid, int e) {

//     vector<int> temp;
//     int left = s;
//     int right = mid + 1;

//     while (left <= mid && right <= e) {

//         if (arr[left] < arr[right]) {
//             temp.push_back(arr[left]);
//             left++;
//         }
//         else {
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }

//     for (int i=s; i<=e; i++) {
//         arr[i] = temp[i-s];
//     }
// }

// void mergeSort(vector<int> &arr, int s, int e) {

//     // Base-condition
//     if (s == e) return;

//     int mid = (s+e)/2;

//     mergeSort(arr,s,mid);
//     mergeSort(arr,mid+1,e);
//     merge(arr,s,mid,e);
// }

// int main () {
//     vector<int> arr = {4,3,5,7,9,1,6};

//     mergeSort(arr, 0, 7);

//     cout<<"Sorted arry"<<endl;
//     for (auto i : arr) {
//         cout<<i<<" ";
//     }cout<<endl;
// }