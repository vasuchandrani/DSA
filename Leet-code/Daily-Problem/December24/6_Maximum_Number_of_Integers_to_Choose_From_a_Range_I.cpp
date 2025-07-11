// link = https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/?envType=daily-question&envId=2024-12-06

#include<bits/stdc++.h>
using namespace std;


// time - O(n^2)
// space - O(1)
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        
        int sum = 0;
        int cnt = 0;
        for (int i=1; i<=n; i++) {
            
            if (find(banned.begin(), banned.end(), i) != banned.end()) {
                continue;
            }
            else {
                sum += i;
                if (sum <= maxSum) {
                    cnt++;
                } else {
                    break;
                }
            }
        }

        return cnt;
    }
};


// time - O(n)
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        
        vector<int> temp(1e4+1, 1);
        for (auto i : banned) {
            temp[i] = 0;
        }
        int cnt = 0;
        for (int i=1; i<=n; i++) {
            if (temp[i] == 0)
                continue;

            if (maxSum >= i) {
                maxSum -= i;
                temp[i] = 0;
                cnt++;   
            }
        }

        return cnt;
    }
};