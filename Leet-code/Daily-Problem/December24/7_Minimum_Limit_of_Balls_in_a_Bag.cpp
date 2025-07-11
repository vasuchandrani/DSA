#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPossible(vector<int>& nums, int maxOpr, int mid) {

        int totalOpr = 0;

        for (int &num : nums) {
            
            int opr = num/mid;
            
            if (num % mid == 0) {
                opr -= 1;
            }
            totalOpr += opr;
        }

        return totalOpr <= maxOpr;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {

        int l = 1;
        int r = *max_element(nums.begin(), nums.end());

        int result = r; // we have to minimize it

        while (l <= r) {
 
            int mid = l + (r-l)/2;

            if (isPossible(nums, maxOperations, mid) == true) {
                result = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1; 
            }
        }

        return result;
    }
};