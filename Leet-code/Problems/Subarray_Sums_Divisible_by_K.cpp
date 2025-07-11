//974

#include<bits/stdc++.h>
using namespace std;

// Brute-force- O(n^2)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n = nums.size();

        // cumulative sum
        for (int i=1; i<n; i++) {
            nums[i] = nums[i] + nums[i-1];
        }

        int cnt = 0;
        for (int i=0; i<n; i++) {
            int sum = 0;
            for (int j=i; j<n; j++) {
                sum = (i == 0) ? nums[j] : nums[j] - nums[i-1];
                if (sum % k == 0) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

// Optimal - O(n)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int> mp;
        mp.insert({0, 1});

        int sum = 0;
        int cnt = 0;
        for (int i=0; i<n; i++) {
            
            sum += nums[i];

            int rem = sum % k;

            if(mp.find(rem) != mp.end()) {
                cnt += mp[rem];
            }

            mp[rem]++;
        }

        return cnt;
    }
};