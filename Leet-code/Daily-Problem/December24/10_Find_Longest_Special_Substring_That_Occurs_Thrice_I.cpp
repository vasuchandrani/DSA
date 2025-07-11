// link = https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/?envType=daily-question&envId=2024-12-10
// 2981

#include<bits/stdc++.h>
using namespace std;

// approach -1 
class Solution {
public:
    int maximumLength(string s) {
        
        int n = s.length();

        unordered_map<string, int> mp;

        for (int i=0; i<n; i++) {
            string curr = "";
            for (int j=i; j<n; j++) {
                if (curr.empty() || curr.back() == s[j]) {
                    curr.push_back(s[j]);
                    mp[curr] += 1;
                } else {
                    break;
                }
            }
        }

        int result = 0;
        for (auto &it : mp) {

            string str = it.first;
            int cnt = it.second;

            if (cnt >= 3 && str.length() > result) {
                result = str.length();
            } 
        }

        return result == 0 ? -1 : result;
    }
};
 

// approach -2
class Solution {
public:
    int maximumLength(string s) {

         

    }    
};