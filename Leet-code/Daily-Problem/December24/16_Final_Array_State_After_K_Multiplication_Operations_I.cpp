// link = 
// 3264

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {

        int n = nums.size();

        for (int i=0; i<k; i++) {
            int min = INT_MAX;
            int idx;
            for(int j=0; j<n; j++) {
                if (min > nums[j]) {
                    min = nums[j];
                    idx = j;
                }
            }
            nums[idx] = nums[idx] * multiplier;
        }

        return nums;      
    }
};                 