// 20/9/2024
// link = https://leetcode.com/problems/shortest-palindrome/?envType=daily-question&envId=2024-09-20

#include<bits/stdc++.h>
using namespace std;


// my approach - time-limit exeed
class Solution {
public:
    bool isPalindrom (string &str, int e) {

        int s = 0;
        while (s < e) {
            if (str[s] != str[e]) {
                return false;
            }
            s++;
            e--;
        }
        return true;
    }

    string shortestPalindrome(string s) {
        
        string str = "";
        for (int i=0; i<s.length(); i++) {
            int end = s.length() - 1 - i;
            if (isPalindrom(s, end)){
                break;
            }
            else {
                str += s[end];
            }   
        }

        if (str.length() != 0)  {
            s = str + s;
        }
        return s;
    }
};


// second approach - memcmp fn 
class Solution {
public:

    string shortestPalindrome(string s) {

        string rev = s;
        reverse(begin(rev), end(rev));

        for(int i=0; i<s.length(); i++) {

            if (!memcmp(s.c_str(), rev.c_str() + i, s.length() - i)){
                return rev.substr(0, i) + s;
            }
        }         

        return rev + s;
    }
};


// best approach - KMP 
class Solution {
public:

    void calculateLPS (string &pat, vector<int> &LPS) {

        int m = pat.length();

        
        int len = 0;
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

    string shortestPalindrome(string s) {
        string rev = s;
        reverse(begin(rev), end(rev));

        string temp = s + "#" + rev;
        vector<int> LPS(temp.length(), 0); //O(n)

        calculateLPS(temp, LPS);

        int longestLPS_length = LPS[temp.length() - 1]; //temp.back();

        string result = rev.substr(0, s.length() - longestLPS_length) + s;  //O(n) -> bcz of subString 

        return result;
    }
};