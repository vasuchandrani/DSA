// 2/11/2024
// link = https://leetcode.com/problems/circular-sentence/?envType=daily-question&envId=2024-11-02

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCircularSentence(string s) {
        
        int n = s.length();

        // check for one word sentence OR
        // first and last char
        if (s[0] != s[n-1]) 
            return false;
        
        // check middle words
        for (int i=0; i<n-1; i++) {
            if (s[i] == ' ') {
                if (s[i-1] != s[i+1]) 
                    return false;
            }
        }

        return true;
    }
};