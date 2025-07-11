// 13/8/2024

// link = https://leetcode.com/problems/combination-sum-ii/description/?envType=daily-question&envId=2024-08-13

#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    void solve(vector<int>& candidates, int &sum, vector<vector<int>>& result, vector<int> &ans, int idx, int target){

        if(sum==target){
            result.push_back(ans);
            return;
        }

        if(idx>=candidates.size() || sum+candidates[idx]>target)
            return;

        sum += candidates[idx];
        ans.push_back(candidates[idx]);
        
        solve(candidates, sum, result, ans, idx+1, target);
        
        ans.pop_back();
        sum -= candidates[idx];
        while(idx + 1 < candidates.size() && candidates[idx] == candidates[idx+1] )
            idx++;
        
        solve(candidates, sum, result, ans, idx+1, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)    {

        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> ans;
        int sum = 0;
	    solve(candidates, sum,  result,  ans,  0, target);
	    return result;
    }
};