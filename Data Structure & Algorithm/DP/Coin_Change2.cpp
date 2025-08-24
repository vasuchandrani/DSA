#include<bits/stdc++.h>
using namespace std;

// return no. of all combinations

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<long long>> t(n + 1, vector<long long>(amount + 1, 0));

        for (int i = 0; i <= n; i++) {
            t[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i - 1] <= j) {
                    // Include coin[i-1] + Exclude coin[i-1]
                    t[i][j] = t[i][j - coins[i - 1]] + t[i - 1][j];
                } else {
                    // Exclude coin[i-1]
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        return t[n][amount]; 
    }
};