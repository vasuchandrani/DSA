#include<bits/stdc++.h>
using namespace std;

class Solution { // O(n*log(k))
public:
    typedef pair<int, int> P;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();      
        vector<int> ans;

        priority_queue<P> pq;

        for (int i=0; i<k; i++) {
            pq.push({nums[i], i});
        }

        ans.push_back(pq.top().first);

        for (int i=k; i<n; i++) {

            while (!pq.empty() && pq.top().second <= i - k) {
                pq.pop();
            }

            pq.push({nums[i], i});

            ans.push_back(pq.top().first);
        }
        return ans;
    }
};