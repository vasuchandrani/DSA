// 15/8/2024

// link = https://leetcode.com/problems/lemonade-change/description/?envType=daily-question&envId=2024-08-15

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five_dollars = 0, ten_dollars = 0;
        
        for (int x : bills) {
            if (x == 5) {
                five_dollars++;
            } else if (x == 10) {
                if (five_dollars > 0) {
                    five_dollars--;
                    ten_dollars++;
                } else {
                    return false;
                }
            } else {
                if (five_dollars > 0 && ten_dollars > 0) {
                    five_dollars--;
                    ten_dollars--;
                } else if (five_dollars > 2) {
                    five_dollars -= 3;
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }
};