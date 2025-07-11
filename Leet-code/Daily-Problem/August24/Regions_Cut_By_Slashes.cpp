// 9/8/2024

/*
An n x n grid is composed of 1 x 1 squares where each 1 x 1 square 
consists of a '/', '\', or blank space ' '. 
These characters divide the square into contiguous regions.
Given the grid grid represented as a string array, return the number of regions.

Note that backslash characters are escaped, so a '\' is represented as '\\'.

link = https://leetcode.com/problems/regions-cut-by-slashes/description/?envType=daily-question&envId=2024-08-10
*/

#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:

    void findSpace (vector<vector<int>>& matrix, int i, int j) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] == 1) {
            return;   
        }

        matrix[i][j] = 1;

        findSpace(matrix, i+1, j);
        findSpace(matrix, i-1, j);
        findSpace(matrix, i, j+1);
        findSpace(matrix, i, j-1);
    }

    int regionsBySlashes(vector<string>& grid) {

        int rows = grid.size();
        int cols = grid.size();

        int regions = 0;
        vector<vector<int>> matrix(rows*3, vector<int>(cols*3, 0));

        for (int i=0;i<rows;i++) {
            for (int j=0;j<cols;j++) {
                if(grid[i][j] == '/') {
                    matrix[i*3][j*3+2] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3] = 1;
                }
                else if(grid[i][j] == '\\') {
                    matrix[i*3][j*3] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3+2] = 1;
                }
            }
        }

        // Applying DFS
        for (int i=0;i<matrix.size();i++) {
            for (int j=0;j<matrix[0].size();j++) {
                if (matrix[i][j] == 0) {
                    findSpace(matrix, i, j);
                    regions++;
                }
            }
        }

        return regions;
    }
};