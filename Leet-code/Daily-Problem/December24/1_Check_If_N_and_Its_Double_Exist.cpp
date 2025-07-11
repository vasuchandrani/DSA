// link = 

#include<bits/stdc++.h>
using namespace std;

// time - O(n^2)
// Brute-Force
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {

        int n = arr.size();

        for (int i=0; i<n; i++) {
            int key = arr[i];
            if (find(arr.begin(), arr.end(), key) != arr.end()) {
                return true;
            }
        }      
        return false;
    }
};

