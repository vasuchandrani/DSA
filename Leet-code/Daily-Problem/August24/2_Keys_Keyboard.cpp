// 19/8/2024

// link = https://leetcode.com/problems/2-keys-keyboard/description/?envType=daily-question&envId=2024-08-19

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        //bottom up + greedy

        if (n == 1) {
            return 0;
        }
        if ( n == 2) {
            return 2;
        }

        vector<int> t(n+1, 0);
        //t[i] == min oprnts required to print i As in the notepad
        //return t[n]

        t[0] = 0;
        t[1] = 0;
        t[2] = 2;

        for (int i=3; i<=n; i++) {
            int factor = i/2;

            while (factor >= 1) {
                if (i%factor == 0) {

                    int printFactorAs = t[factor];
                    int copy = 1;
                    int paste = (i / factor) - 1;

                    t[i] = printFactorAs + copy + paste;
                    break;
                } else {
                    factor--;
                }
            }
        }
        return t[n];
    }
};