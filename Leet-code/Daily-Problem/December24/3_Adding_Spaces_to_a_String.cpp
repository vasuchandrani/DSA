// 3/12/2024
// link = https://leetcode.com/problems/adding-spaces-to-a-string/description/?envType=daily-question&envId=2024-12-03

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {

        int l = s.length();
        int n = spaces.size();

        string result(l+n,' ');

        int j = 0;
        for (int i=0; i<l; i++) {
            if (j < n && i == spaces[j]) {
                result[i+j] = ' ';
                j++;
            }
            result[i+j] = s[i];
        }
        return result;
    }
};

