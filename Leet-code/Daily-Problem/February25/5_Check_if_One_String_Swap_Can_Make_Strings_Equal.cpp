// 1790

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        int n = -1, m = -1;
        int cnt = 0;
        for (int i=0; i<s1.length(); i++) {
            if (s1[i] != s2[i]) {
                cnt++;
                if (n == -1) n = i;
                else if (m == -1) m = i;
            }
        }
        if (cnt == 0) {
            return true;
        }
        else if (cnt == 2 && s1[n] == s2[m] && s1[m] == s2[n]) {
            return true;
        }

        return false;
    }
};