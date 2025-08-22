#include<iostream>
#include<math.h>
#include<vector>
#include<string>
using namespace std;

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        vector<int> prefMax(n);
        vector<int> suffMax(n);
        vector<int> ans;
        
        //prefMax 
        for (int i=0; i<n; i++) {
            if (i % k == 0) { //new window
                prefMax[i] = nums[i]; 
            }
            else {
                prefMax[i] = max(prefMax[i-1], nums[i]);
            } 
                
        }
        
        //suffMax
        for (int i=n-1; i>=0; i--) {
            if ((i +1) %k == 0 || i == n-1) {
                suffMax[i] = nums[i];
            }
            else {
                suffMax[i] = max(suffMax[i+1], nums[i]);
            }
        }
        
        for (int i=0; i<=n-k; i++) {
            ans.push_back(max(prefMax[i+k-1], suffMax[i]));
        }
        
        return ans;
    }
};
