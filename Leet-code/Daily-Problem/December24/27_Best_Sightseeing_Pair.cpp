// 1014

#include<bits/stdc++.h>
using namespace std;

// approach -1: use space (vector)
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        int n = values.size();
        vector<int> maxLeftVal(n, 0);

        maxLeftVal[0] = values[0] + 0;
        for (int i=1; i<n; i++) {
            maxLeftVal[i] = max(values[i]+i, maxLeftVal[i-1]);
        }

        int sum = 0;
        for (int j=1; j<n; j++) {
            sum = max(sum, (values[j]-j + maxLeftVal[j-1]));
        }

        return sum;
    }
};


// approach -2: use only one variable
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        int n = values.size();

        int maxVal = values[0] + 0;
        int ans = 0;
        for (int j=1; j<n; j++) {
            
            ans = max(ans, values[j]-j + maxVal);
            maxVal = max(maxVal, values[j]+j);
        }

        return ans;
    }
};