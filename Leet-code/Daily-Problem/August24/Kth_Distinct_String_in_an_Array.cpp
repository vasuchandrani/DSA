// 5/8/2024

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        
        unordered_map<string, int> m;
        int n = arr.size();
        for (int i=0;i<n;i++) {
            m[arr[i]]++;
        }

        for (int i=0;i<n;i++) {
            if (m[arr[i]] == 1){
                k--;
                if(k==0) return arr[i];
            }
        }
        return "";
    }
};