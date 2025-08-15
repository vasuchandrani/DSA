/*
Given an array of n numbers, sorted in non-decreasing order, and k queries. 
For each query, print the maximum index of an array element not greater than the given one.
*/


#include<bits/stdc++.h>
using namespace std;

int main () {
    int n;  cin>>n;
    int k;  cin>>k;

    vector<int> a(n);
    for (int i=0; i<n; i++) cin>>a[i];

    for (int i=0; i<k; i++) {
        int x;  cin>>x;

        int l = 0;
        int r = n-1;
        int idx = -1;

        while (l <= r) {

            int mid = (l + r)/2;

            if (a[mid] <= x) {
                idx = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        cout<<idx + 1 <<endl;
    }
    return 0;
}