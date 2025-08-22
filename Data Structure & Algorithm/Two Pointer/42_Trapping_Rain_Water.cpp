#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int lMax = height[l];
        int rMax = height[r];
        int wtr = 0;

        // [4, 2, 0, 3, 2, 5]
        //           L     R   
        while (l < r) {
            if (lMax < rMax) {
                l++;
                lMax = max(lMax, height[l]);
                wtr += lMax - height[l];
            } 
            else {
                r--;
                rMax = max(rMax, height[r]);
                wtr += rMax - height[r];
            }
        }
        return wtr;        
    }
};