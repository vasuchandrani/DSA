#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int s, int i, int j, vector<vector<int>>& waitCost, int n, int m, vector<vector<vector<long long>>>& dp) {
        if (i == n - 1 && j == m - 1) 
            return 0;

        if (dp[s % 2][i][j] != -1) 
            return dp[s % 2][i][j];

        long long right = LLONG_MAX;
        long long down = LLONG_MAX;

        if (s % 2 == 0) {
            dp[s % 2][i][j] = waitCost[i][j] + solve(s + 1, i, j, waitCost, n, m, dp);
        } else {
            if (i < n - 1)
                right = (i + 2) * (j + 1) + solve(s + 1, i + 1, j, waitCost, n, m, dp);
            if (j < m - 1)
                down = (i + 1) * (j + 2) + solve(s + 1, i, j + 1, waitCost, n, m, dp);

            dp[s % 2][i][j] = min(right, down);
        }

        return dp[s % 2][i][j];
    }

    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        
        vector<vector<vector<long long>>> dp(2, vector<vector<long long>>(m, vector<long long>(n, -1)));

        return 1 + solve(1, 0, 0, waitCost, m, n, dp);
    }
};