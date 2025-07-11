// 11/8/2024

// link = https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/?envType=daily-question&envId=2024-08-11

#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int n, m;

    void DFS(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis) {
        if(i < 0 || i >= m || j < 0 || j >= n || vis[i][j] || grid[i][j] == 0){
            return;
        } 

        vis[i][j] = true; //mark visited

        DFS(grid, i+1, j, vis);
        DFS(grid, i-1, j, vis);
        DFS(grid, i, j+1, vis);
        DFS(grid, i, j-1, vis);
    }

    int numberOfIslandsUtil(vector<vector<int>>& grid) {
        int islands = 0;

        vector<vector<bool>> vis(m, vector<bool>(n));

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j] == 1 && !vis[i][j]) { // land
                    DFS(grid, i, j, vis);
                    islands++;
                }
            }
        }

        return islands;
    }

    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int islands = numberOfIslandsUtil(grid);
        if (islands > 1 || islands == 0) {
            return 0;
        }
        else { //we have only one island
            //Check if we can disconnect the grid in one day

            for (int i=0;i<m;i++) {
                for (int j=0;j<n;j++) {
                    if(grid[i][j] == 1) {

                        grid[i][j] = 0; //covert to water

                        islands = numberOfIslandsUtil(grid);
                        if(islands > 1 || islands == 0) {
                            return 1;
                        }

                        grid[i][j] = 1; //make it land again and now go to try next cell
                    }
                }
            }
        }

        return 2;
    }
};