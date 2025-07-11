// 3105

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int max_inc = 1;
        int temp = 1;
        for (int i=0; i<n-1; i++) {
            if (nums[i] < nums[i+1]) {
                temp++;
            }
            else {
                max_inc = max(max_inc, temp);
                temp = 1;
            }
        }
        max_inc = max(max_inc, temp);
        
        temp = 1;
        int max_dec = 1;
        for (int i=0; i<n-1; i++) {
            if (nums[i] > nums[i+1]) {
                temp++;
            }
            else {
                max_dec = max(max_dec, temp);
                temp = 1;
            }
        }
        max_dec = max(max_dec, temp);
        

        return (max_inc > max_dec) ? max_inc : max_dec;
    }
};