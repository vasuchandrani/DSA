// 3/11/2024
// link = https://leetcode.com/problems/rotate-string/?envType=daily-question&envId=2024-11-03

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {

        if (s.length() != goal.length()) 
            return false;

        return (s + s).find(goal) != string::npos;
    }
};