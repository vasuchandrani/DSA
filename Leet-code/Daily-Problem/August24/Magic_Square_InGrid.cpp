// 9/8/2024

/*
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 
such that each row, column, and both diagonals all have the same sum.
Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?

Note: while a magic square can only contain numbers from 1 to 9, 
grid may contain numbers up to 15.
*/

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    bool isMagicGrid(vector<vector<int>> &grid, int r, int c) {
        
        unordered_set<int> st;
        for (int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                int num = grid[r+i][c+j];
                if (num < 1 || num > 9 || st.count(num)){
                    return false;
                } else {
                    st.insert(num);
                }
            }
        }

        int SUM = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        for (int i=0;i<3;i++) {
            if (grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != SUM) {
                return false;
            }

            if (grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i] != SUM) {
                return false;
            }
        }

        if (grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != SUM) {
            return false;
        }

        
        if (grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != SUM) {
            return false;
        }

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows  = grid.size();
        int cols  = grid.size();

        int count = 0;

        for (int i=0 ; i<=rows - 3 ; i++) {
            for (int j=0 ; j<=cols - 3 ; j++) {
                if (isMagicGrid(grid, i, j)) {
                    count++;
                }
            }
        }

        return count;
    }
};