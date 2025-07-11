// link = https://leetcode.com/problems/move-pieces-to-obtain-a-string/description/?envType=daily-question&envId=2024-12-05

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        
        int n = start.length();

        int i = 0;
        int j = 0;

        while (i < n || j < n) {

            while (i < n && start[i] == '_'){
                i++;
            }

            while (j < n && target[j] == '_'){
                j++;
            }

            if (i == n || j == n) {
                return i == j;
            }

            if(start[i] != target[j]) {
                return false;
            }

            if (start[i] == 'L' && i < j) {
                return false;
            }

            if (start[i] == 'R' && j < i) {
                return false;
            }

            i++;
            j++;
        }
        return true;
    }
};