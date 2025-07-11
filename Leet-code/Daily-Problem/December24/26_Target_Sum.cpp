// 494

#include<bits/stdc++.h>
using namespace std;

// approach -1, easy, bute-force
class Solution {
public:
    int solve (vector<int> &nums, int target, int i, int currSum) {

        if (i == nums.size()) {
            if (currSum == target) {
                return 1;
            }
            else {
                return 0;
            }
        }

        int plus = solve(nums, target, i+1, currSum + nums[i]);
        int minus = solve(nums, target, i+1, currSum - nums[i]);

        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        return solve(nums, target, 0, 0);         
    }
};


// approach -2, memoization by map, for handle nagetive numbers
class Solution {
public:

    int solve (vector<int> &nums, int target, int i, int currSum, unordered_map<string, int>& mp) {

        if (i == nums.size()) {
            if (currSum == target) {
                return 1;
            }
            else {
                return 0;
            }
        }

        string key = to_string(i) + "_" + to_string(currSum);

        if (mp.count(key)) { 
            // mp.find(key) != mp.end()
            return mp[key];
        }

        int plus = solve(nums, target, i+1, currSum + nums[i], mp);
        int minus = solve(nums, target, i+1, currSum - nums[i], mp);

        return mp[key] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        unordered_map<string, int> mp;
        return solve(nums, target, 0, 0, mp);         
    }
};


// approach -3, memoization by 2D vector.
class Solution {
public:
    int S;
    int solve (vector<int> &nums, int target, int i, int currSum, vector<vector<int>>& t) {

        if (i == nums.size()) {
            if (currSum == target) {
                return 1;
            }
            else {
                return 0;
            }
        }

        if (t[i][currSum + S] != -1) {
            return t[i][currSum + S];
        }

        int plus = solve(nums, target, i+1, currSum + nums[i], t);
        int minus = solve(nums, target, i+1, currSum - nums[i], t);

        return t[i][currSum + S] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        S = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> t(n+1, vector<int>(2*S+1, -1));
        return solve(nums, target, 0, 0, t);         
    }
};