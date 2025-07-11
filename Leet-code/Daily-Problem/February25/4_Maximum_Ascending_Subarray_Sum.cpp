// 1800

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {

        int n = nums.size();
        int sum = 0;
        int temp = 0;
        for (int i=0; i<n; i++) {
            if (i > 0 && nums[i] <= nums[i-1]) {
                sum = max(sum, temp);
                temp = 0;
            }  
            temp += nums[i];
        }
        sum = max(sum, temp);
        return sum;
    }
};