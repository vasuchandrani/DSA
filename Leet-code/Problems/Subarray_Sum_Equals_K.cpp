//560

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        int cnt = 0;

        int prevSum = 0;
        mp.insert({0, 1});

        for (int i=0; i<nums.size(); i++) {

            prevSum += nums[i];

            if (mp.find(prevSum - k) != mp.end()) {
                cnt += mp[prevSum - k];
            }

            mp[prevSum]++;
        }
        return cnt;
    }
};