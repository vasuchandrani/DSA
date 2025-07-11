#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {

        vector<int> mp(26, 0);

        if(word.length() <= 8) {
            return word.length();
        }
        else {
            for (char &ch : word) {
                mp[ch-'a']++;
            }

            sort(begin(mp), end(mp), greater<int>()); //decending order 

            int push = 0;
            for (int i=0;i<26;i++) {
                int freq = mp[i];
                int press = i/8 + 1;
                push += press * freq;
            }
            return push;
        }
    }
};