// link = 
// 2779

#include<bits/stdc++.h>
using namespace std;

// approach -1
// interval-base-problem
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {

        int n = nums.size();
        vector<pair<int, int>> intervals(n);      

        for (int i=0; i<n; i++) {

            intervals[i] = {nums[i]-k, nums[i]+k};
        }

        sort(intervals.begin(), intervals.end());

        queue<int> q;
        int maxBeauty = 0;

        for (pair<int, int>& interval : intervals) {

            while (!q.empty() && q.front() < interval.first) {
                q.pop();
            }

            q.push(interval.second);

            maxBeauty = max(maxBeauty, (int)q.size());
        }

        return maxBeauty;         
    }
};


// approach -2
// binary-search
class Solution {
public:

    int binarySearch(vector<int>& nums, int y) {

        int l = 0;
        int r = nums.size()-1;
        int result = 0;

        while (l <= r) {
            int mid = l + (r-l)/2;

            if (nums[mid] <= y){
                result = mid;
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }

        return result;
    }

    int maximumBeauty(vector<int>& nums, int k) {

        int n = nums.size();
        
        sort(nums.begin(), nums.end());

        int maxBeaty = 0;

        for (int i=0; i<n; i++) {
            
            int y = nums[i] + 2*k; 
            int j = binarySearch(nums, y);

            maxBeaty = max(maxBeaty, j-i+1);
        }
        return maxBeaty;
    }
};


// approach -3
// sliding-window
class Solution {
public:

    int maximumBeauty(vector<int>& nums, int k) {
  
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = 0;

        int maxBeauty = 0;
        
        while (i < n) {
            while (j < n && nums[j] <= nums[i] + 2*k) {
                j++;
            }

            maxBeauty = max(maxBeauty, j-i);
            i++;
        }

        return maxBeauty;
    }
};