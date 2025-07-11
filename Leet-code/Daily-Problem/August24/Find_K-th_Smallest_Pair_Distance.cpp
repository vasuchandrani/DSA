// 14/8/2024

// link = https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/?envType=daily-question&envId=2024-08-14

#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<climits>
using namespace std;

// time limit exeed -> 
// class Solution {
// public:
//     int smallestDistancePair(vector<int>& nums, int k) {
        
//         priority_queue<int, vector<int>, greater<int>> pq;

//         for (int i=0; i<nums.size(); i++) {
//             for (int j=i+1; j<nums.size(); j++) {
//                 pq.push(abs(nums[j]-nums[i]));
//             }
//         }

//         int temp = k-1;
//         while (temp--) {
//             pq.pop();
//         }

//         return pq.top();

        
//     }
// };

// correct solution ->
class Solution {
public:
    int countPairs(vector<int>& nums, int mid) {
        int count = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            while (j < nums.size() && nums[j] - nums[i] <= mid) {
                ++j;
            }
            count += j - i - 1;
        }
        return count;
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int low = 0;
        int high = nums.back() - nums.front();
        
        while (low < high) {
            int mid = (low + high) / 2;
            if (countPairs(nums, mid) >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};
