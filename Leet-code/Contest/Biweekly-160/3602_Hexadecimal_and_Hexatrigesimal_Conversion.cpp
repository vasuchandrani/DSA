#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string concatHex36(int n) {

        int m = n*n;
        int k = n*n*n;

        string s1 = "";

        for (int i = 0; m > 0; i++) {
            int x = m % 16;

            if (x >= 10) {
                s1 = char('A' + (x - 10)) + s1;
            } else {
                s1 = char('0' + x) + s1;
            }

            m /= 16;
        }

        string s2 = "";
         for (int i = 0; k > 0; i++) {
            int x = k % 36;

            if (x >= 10) {
                s2 = char('A' + (x - 10)) + s2;
            } else {
                s2 = char('0' + x) + s2;
            }

            k /= 36;
        }

        return s1 + s2;   
    }
};