// 4/8/2024

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int M = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {

        vector<int> subarry;

        for (int i=0;i<n;i++) {
            int ele = nums[i];
            subarry.push_back(ele);
            for (int j=i+1;j<n;j++) {
                ele += nums[j];
                subarry.push_back(ele);
            }
        }
        sort(subarry.begin(), subarry.end());

        int sum = 0;
        for (int i=left-1;i<right;i++) {
            sum = (sum + subarry[i]) % M;
        }
        return sum;
    }
};