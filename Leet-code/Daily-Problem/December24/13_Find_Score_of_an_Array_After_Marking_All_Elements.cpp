// link = 
// 2593

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {

        int n = nums.size();

        vector<pair<long long, int>> v(n);
        for (int i=0; i<n; i++) {
            v[i] = {nums[i], i};
        }

        sort(v.begin(), v.end());
        vector<bool> visited(n, false);

        long long scr = 0;

        for (auto i : v) {
            
            if (!visited[i.second]) {
                scr += i.first;
                visited[i.second] = true;

                if (i.second + 1 < n)
                    visited[i.second + 1] = true;

                if (i.second - 1 >= 0)
                    visited[i.second - 1] = true;

            }
            else {
                continue;
            }
        }

        return scr;
    }
};