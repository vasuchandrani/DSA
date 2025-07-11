#include<bits/stdc++.h>
using namespace std;


// class Solution {
// public:
//     int partitionString(string s) {

//         int n = s.length();
//         unordered_set<char> st;
//         int cnt = 0;
//         for (int i=0; i<n; i++) {
//             if (st.find(s[i]) == st.end()) {
//                 st.insert(s[i]);
//             }
//             else {
//                 cnt++;
//                 st.clear();
//             }
//         }      
//         return cnt;
//     }
// };


class Solution {
public:
    int partitionString(string s) {

        int n = s.length();
        vector<int> seenedChar(26, 0);

        int cnt = 1;
        for (int i=0; i<n; i++) {
            
            if (seenedChar[s[i] - 'a'] < cnt) {
                seenedChar[s[i] - 'a'] = cnt;
            }
            else {
                cnt++;
                seenedChar[s[i] - 'a'] = cnt;
            }

        }      
        return cnt;
    }
};