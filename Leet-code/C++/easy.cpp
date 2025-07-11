#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int j = i+1;
            while(j<n){
                if(nums[i] + nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};