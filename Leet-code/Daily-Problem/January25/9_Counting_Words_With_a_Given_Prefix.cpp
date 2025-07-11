// 2185

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrefix(string pref, string word){
        if(word.substr(0, pref.size()) == pref){
            return true;
        }
        return false;
    }
    int prefixCount(vector<string>& words, string pref) {
        int n= words.size();
        int count=0;
        for(int i=0; i<n; i++){
            if(isPrefix(pref, words[i])){
                count++;
            }
        }
        return count;
    }
};