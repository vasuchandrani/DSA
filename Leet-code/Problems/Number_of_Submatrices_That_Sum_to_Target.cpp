//1074

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();

        // First take row vise cumulative sum
        for (int row=0; row<rows; row++) {
            for (int col=1; col<cols; col++) {
                matrix[row][col] += matrix[row][col-1];
            }
        }

        // Now, find No. of subArry with sum == target
        int cnt = 0;

        for (int startCol=0; startCol<cols; startCol++) {

            for (int j=startCol; j<cols; j++) {

                unordered_map<int, int> mp;
                mp.insert({0, 1});
                int prevSum = 0;    //cumSum

                for (int row=0; row<rows; row++) {
                    prevSum += matrix[row][j] - (startCol > 0 ? matrix[row][startCol-1] : 0);
                
                    if (mp.find(prevSum - target) != mp.end()) {
                        cnt += mp[prevSum - target];
                    }

                    mp[prevSum]++;
                }
            }
        }
        return cnt;
    }
};