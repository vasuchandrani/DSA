#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 

    // DFS
    // bool checkSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {

    //     if (i < 0 || i >= grid1.size() || j < 0 || j >= grid2.size()) {
    //         return true;
    //     }
    //     if (grid2[i][j] != 1) { // ignore non-land
    //         return true;
    //     }

    //     grid2[i][j] = -1;   // visited

    //     bool result = {grid1[i][j] == 1};   // waha par 1 hai kya?

    //     result = result & checkSubIsland(grid1, grid2, i+1, j); //Down
    //     result = result & checkSubIsland(grid1, grid2, i-1, j); //Up
    //     result = result & checkSubIsland(grid1, grid2, i, j+1); //Right
    //     result = result & checkSubIsland(grid1, grid2, i, j-1); //Left

    //     return result;
    // }

    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    // BFS
    bool checkSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {

        int m = grid1.size();
        int n = grid1[0].size();

        bool result = true;

        queue<pair<int,int>> q; // {i, j}
        q.push({i, j});
        grid2[i][j] = -1;   // visited

        while (!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            if (grid1[x][y] != 1) {
                result = false;
            }
             
            for (vector<int> dir : directions) {
                int newX = x + dir[0];
                int newY = y + dir[1];
            } 

        }

    }


    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        //DFS
        int subIsland = 0;
        int m = grid2.size();   //rows
        int n = grid2[0].size();//cols

        for (int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid2[i][j] == 1 && checkSubIsland(grid1, grid2, i, j)) {    //found an island
                    subIsland++;
                }
            }
        }
        return subIsland;
    }
};