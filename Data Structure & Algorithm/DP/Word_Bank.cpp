#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& w) {
        
        unordered_set<string> dict(w.begin(), w.end());
        
        int n = s.size() ;

        vector<int> dp(n+1, false);
        dp[0] = true;

        for(int i=1; i<=n; i++){
        
            for(int j=0; j<i; j++){
                
                if(dp[j] && dict.find(s.substr(j,i-j)) != dict.end()){
                
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};