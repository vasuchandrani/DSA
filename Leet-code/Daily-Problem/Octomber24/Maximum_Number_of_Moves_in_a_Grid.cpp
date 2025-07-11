// 29/10/2024
// link = https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description/?envType=daily-question&envId=2024-10-29

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m;  // rows
    int n;  // cols
    vector<int> diractions = {-1, 0, 1};

    int DFS (int row, int col, vector<vector<int>>& grid, vector<vector<int>>& t) {

        if (t[row][col] != -1) {
            return t[row][col];
        }

        int moves = 0;
        for (int dir : diractions) {
            int newRow = row + dir;
            int newCol = col + 1;

            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] > grid[row][col]) {
                moves = max(moves, 1 + DFS(newRow, newCol, grid, t));
            }
        }

        return t[row][col] = moves;
    }

    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> t(m, vector<int>(n, -1));
        
        int result = 0;
        for (int row=0; row<m; row++) {
            result = max(result, DFS(row, 0, grid, t));
        }        

        return result;
    }
};