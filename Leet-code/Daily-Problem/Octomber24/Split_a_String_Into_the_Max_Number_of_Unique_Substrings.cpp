// 21/10/2024
// link = https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/?envType=daily-question&envId=2024-10-21

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve (string &s, int i, unordered_set<string>& st, int currCount, int &maxCount) {
        
        if (currCount + (s.length() - i) <= maxCount) {
            return;
        }


        if (i >= s.length()) {
            maxCount = max(maxCount, currCount);
            return;
        }

        for (int j=i; j<s.length(); j++) {
            string sub = s.substr(i, j-i+1);    //O(n)

            if (st.find(sub) == st.end()) {
                st.insert(sub);  //Do
                solve(s, j+1, st, currCount+1, maxCount); //Explore 
                st.erase(sub); //Undo
            }
        }
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> st;

        int maxCount = 0;
        int currCount = 0;
        int i = 0;
        solve (s, i, st, currCount, maxCount);

        return maxCount;
    }
};