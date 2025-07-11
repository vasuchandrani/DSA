// 3/10/2024
// link = https://leetcode.com/problems/make-sum-divisible-by-p/description/?envType=daily-question&envId=2024-10-03

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        int n = nums.size();
        int SUM = 0;

        // (a+b) % p = (a%p + b%p) % p
        for (int &num : nums) {
            SUM = (SUM + num) % p; 
        }

        int target = SUM % p;

        if (target == 0) {
            return 0;
        }

        unordered_map<int , int> mp;

        int curr = 0;
        mp[0] = -1;

        int ans = INT_MAX;
        for (int i=0; i<n; i++) {
            curr = (curr + nums[i]) % p;

            int remain = (curr - target + p) % p;
 
            if (mp.find(remain) != mp.end()) {
                ans = min(ans, i - mp[remain]);                
            }

            mp[curr] = i;
        }
        return (ans == INT_MAX) ? -1 : ans;     
    }
};
