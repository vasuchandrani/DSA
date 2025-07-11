// 3151

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& a) {
        
        int n = a.size();

        for (int i=0; i<n; i++) {
            if (a[i] % 2 == 0) {
                if ((i+1 < n) && (a[i+1] % 2 == 0)) {
                    return false;
                }
            }
            else {
               if ((i+1 < n) && (a[i+1] % 2 != 0)) {
                    return false;
                } 
            }
        }
        return true;
    }
};
