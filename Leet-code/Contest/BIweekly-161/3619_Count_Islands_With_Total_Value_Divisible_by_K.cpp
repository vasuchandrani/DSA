#include <bits/stdc++.h>
using namespace std;
#define ll long long 

class Solution {
public:
    int N, M, K;

    void solve(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis, ll& sum) {
        if (i < 0 || j < 0 || i >= N || j >= M || vis[i][j] || grid[i][j] == 0)
            return;

        vis[i][j] = true;
        sum += grid[i][j];

        solve(i + 1, j, grid, vis, sum);
        solve(i - 1, j, grid, vis, sum);
        solve(i, j + 1, grid, vis, sum);
        solve(i, j - 1, grid, vis, sum);
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        N = grid.size();
        M = grid[0].size();
        K = k;

        vector<vector<bool>> vis(N, vector<bool>(M, false));
        int ans = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!vis[i][j] && grid[i][j] != 0) {
                    ll sum = 0;
                    solve(i, j, grid, vis, sum);
                    if (sum % K == 0)
                        ans++;
                }
            }
        }

        return ans;
    }
};