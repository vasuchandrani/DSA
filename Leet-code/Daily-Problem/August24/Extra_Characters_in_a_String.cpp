// 23/9/2024
// link = https://leetcode.com/problems/extra-characters-in-a-string/description/?envType=daily-question&envId=2024-09-23

#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int t[51];
//     int solve(int i, string s, unordered_set<string> &st, int &n) {

//         if (i >= n) {
//             return 0;
//         }

//         if (t[i] != -1) {
//             return t[i];
//         }

//         int result = 1 + solve(i+1, s, st, n);
        
//         for(int j=i; j<n; j++) {
//             string curr = s.substr(i, j-i+1);
//             if (st.count(curr)){
//                 result = min(result, solve(j+1, s, st, n));
//             }
//         }

//         return t[i] = result;
//     }

//     int minExtraChar(string s, vector<string>& dictionary) {
        
//         int n = s.length();
//         memset(t, -1, sizeof(t));

//         unordered_set<string> st(begin(dictionary), end(dictionary));


//         return solve (0, s, st, n);
//     }
// };



class Solution {
public:

    int solve(int i, string s, unordered_set<string> &st, int &n, unordered_map<int, int> &mp) {

        if (i >= n) {
            return 0;
        }

        if (mp.count(i)) {
            return mp[i];
        }

        int result = 1 + solve(i+1, s, st, n, mp);
        
        for(int j=i; j<n; j++) {
            string curr = s.substr(i, j-i+1);
            if (st.count(curr)){
                result = min(result, solve(j+1, s, st, n, mp));
            }
        }

        return mp[i] = result;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        
        int n = s.length();
        unordered_map<int, int> mp;

        unordered_set<string> st(begin(dictionary), end(dictionary));


        return solve (0, s, st, n, mp);
    }
};