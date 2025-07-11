// 689

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

class Solution {
public:
    int t [20001][4];

    int Helper(vector<int>& subArry, int cnt, int i, int k) {
        if (cnt == 0) {
            return 0;
        }

        if (i >= subArry.size()) {
            return INT_MIN;
        }

        if (t[i][cnt] != -1) {
            return t[i][cnt];
        }

        int take = subArry[i] + Helper(subArry, cnt-1, i+k, k);
        int skip = Helper(subArry, cnt, i+1, k);

        return t[i][cnt] = max(take, skip);
    }

    void solve(vector<int>& subArry, int cnt, int i, int k, vector<int>& result) {

        if (cnt == 0) {
            return;
        }
        if (i >= subArry.size()) {
            return;
        }

        int take_i = subArry[i] + Helper(subArry, cnt-1, i+k, k);
        int skip_i = Helper(subArry, cnt, i+1, k);

        if (take_i >= skip_i) {
            result.push_back(i);
            solve(subArry, cnt-1, i+k, k, result);
        } else {
            solve(subArry, cnt, i+1, k, result);
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {

        memset(t, -1, sizeof(t));

        int n = nums.size();
        vector<int> subArry(n);
        int i = 0;
        int j = 0;
        int sum = 0;

        while (j < n) {

            sum += nums[j];

            if (j-i+1 == k) {
                subArry[i] = sum;
                sum -= nums[i];
                i++;
            }
            j++;
        }

        vector<int> result;
        solve(subArry, 3, 0, k, result);

        return result;
    }
};