// 27/08/2024
// link - https://leetcode.com/problems/two-sum/?envType=daily-question&envId=2024-08-27

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        for(int i=0; i<n; i++){
            
            int j = i+1;
            while(j < n) {
                if(nums[i] + nums[j] == target) {
                    return {i,j};
                }
                j++;
            }
        }
        return {};
    }
};