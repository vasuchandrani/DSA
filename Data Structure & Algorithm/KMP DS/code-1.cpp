#include<bits/stdc++.h>
using namespace std;

class Solution {

public:

    void calculateLPS (int m, string &pat, vector<int> &LPS) {

        // length of prev longest prefix & suffix
        int len = 0;

        // bcz there is no proper prefix & suffix of pat(0-0)
        LPS[0] = 0;

        int i = 1;
        while (i < m) {

            if (pat[i] == pat[len]) {
                len++;
                LPS[i] = len;
                i++;
            } else {
                if (len > 0) {
                    len = LPS[len - 1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }

    vector<int> search(string pat, string text) {

        int n = text.length(); 
        int m = pat.length();

        vector<int> result;

        // make LPS : longest proper prefix / suffix
        vector<int> LPS(m, 0);
        calculateLPS(m, pat, LPS);

        // KMP likho
        int i = 0;
        int j = 0;

        while (i < n) {

            if (text[i] == pat[j]) {
                i++;
                j++;
            }
            else if (text[i] != pat[j]) {
                
                if (j > 0) {
                    j = LPS[j-1];
                }
                else {
                    i++;
                }
            }
            else if (j == m) {
                result.push_back(i - m);
                j = LPS[j-1];
            }
        }

        return result;
    }
};