// link = 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();
        int m = queries.size();

        vector<int> cumSum(n, 0);
        // cumSum[i] = total count of violating indices

        cumSum[0] = 0;

        for (int i=1; i<n; i++) {
            if (nums[i] % 2 == nums[i-1] % 2) {
                // violating idx
                cumSum[i] = cumSum[i-1] + 1;
            }
            else {
                cumSum[i] = cumSum[i-1];
            }
        }   

        vector<bool> result(m, false);

        int i = 0; 
        for (vector<int> &q : queries) {
            int s = q[0];
            int e = q[1];

            if (cumSum[e] - cumSum[s] == 0) {
                result[i] = true;
            }
            i++;
        }
        return result;
    }
};


// second approach
class Solution {
public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {

        int n = nums.size();
        int m = queries.size();

        vector<int> validRightMostIdx(n);
        // valid end point of ith start point

        int i = 0;
        int j = 0;

        while (i < n) {
            if (j < i) {
                j = i;
            }

            while (nums[j]%2 != nums[j+1]%2 && j+1 < n) {
                j++;
            }

            validRightMostIdx[i] = j;
            i++;
        }

        vector<bool> result(m, false);

        for (int i=0; i<m; i++) {
            int s = queries[i][0];
            int e = queries[i][1];

            if (e <= validRightMostIdx[s]) {
                result[i] = true;
            }
        }

        return result;
    }
};