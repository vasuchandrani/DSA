// 1/11/2024
// link = https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/?envType=daily-question&envId=2024-11-01

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        
        int n = s.length();

        string ans = "";
        ans.push_back(s[0]);
        int cnt = 1;
        for (int i=1; i<n; i++) {
            if (s[i] == ans.back()) {
                cnt++;
                if (cnt < 3)
                    ans.push_back(s[i]);
            }
            else {
                cnt = 1;
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};