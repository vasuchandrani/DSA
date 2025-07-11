// 21/9/2024
// link = https://leetcode.com/problems/lexicographical-numbers/?envType=daily-question&envId=2024-09-21

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve (int currNum, int n, vector<int> &result) {

        // base-case
        if (currNum > n) {
            return;
        }

        result.push_back(currNum);

        for (int i=0; i<=9; i++) {

            int num = currNum * 10 + i;

            if (num > n) {
                return;
            }
            solve(num, n, result);
        }
    }

    vector<int> lexicalOrder(int n) {
    
        vector<int>result;
        for (int i=1; i<=9; i++) {
            solve(i, n, result);
        }

        return result;
    }
};