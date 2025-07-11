// link = 
// 

#include<bits/stdc++.h>
using namespace std;

// approach -1
// map/ sliding window
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {

        int n = nums.size(); 

        map<int, int> mp;

        int i = 0;
        int j = 0;

        long long cnt = 0;

        while (j < n) {
            mp[nums[j]]++;

            while (abs(mp.rbegin()->first - mp.begin()->first) > 2) {

                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }

            cnt += j-i+1;
            j++;
        }

        return cnt;
    }
};

// approach -2/
// priority queue
class Solution {
public:
    #define P pair<int, int> 
    long long continuousSubarrays(vector<int>& nums) {

        int n = nums.size();

        priority_queue<P> maxHeap;
        priority_queue<P, vector<P>, greater<P>> minHeap;

        int i = 0;
        int j = 0;
        long long cnt = 0;

        while (j < n) {
            minHeap.push({nums[j], j});
            maxHeap.push({nums[j], j});

            while (abs(maxHeap.top().first - minHeap.top().first) > 2) {
                i++;

                while (!maxHeap.empty() && maxHeap.top().second < i) {
                    maxHeap.pop();
                }
                while (!minHeap.empty() && minHeap.top().second < i) {
                    minHeap.pop();
                }
            }

            cnt += j-i + 1;
            j++;
        } 
        return cnt;
    }
};