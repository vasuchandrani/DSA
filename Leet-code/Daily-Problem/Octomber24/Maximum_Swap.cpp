#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:

//     int maximumSwap(int num) {
//         string s = to_string(num);
//         int n = s.length();

//         vector<int> maxRight(n);

//         maxRight[n-1] = n-1;
//         for (int i=n-2; i>=0; i--) {
//             int rightMaxIdx = maxRight[i+1];

//             if (s[rightMaxIdx] < s[i]) {
//                 maxRight[i] = i;
//             }
//             else {
//                 maxRight[i] = rightMaxIdx;
//             }
//         }

//         for (int i=0; i<n; i++) {
//             int maxRightIdx = maxRight[i];

//             if (s[i] < s[maxRightIdx]) {
//                 swap(s[i], s[maxRightIdx]);
//                 return stoi(s);
//             }
//         }
//         return num;
//     }
// };


class Solution {
public:
    int maximumSwap(int num) {
        
        string s = to_string(num);
        int n = s.length();

        vector<int> maxRight(10, -1);

        for (int i=0; i<n; i++) {
            int idx = s[i] - '0';
            maxRight[idx] = i;
        }

        for (int i=0; i<n; i++) {
            int currDigit = s[i] - '0';

            for (int digit=9; digit>currDigit; digit--) {
                if (maxRight[digit] > i) {
                    swap(s[i], s[maxRight[digit]]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};