#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void solve(int n, vector<int>& nums, int &sumOfSingleDigit, int &sumOfDoubleDigit){
        
        for(int i=0;i<n;i++){
            int temp = nums[i]/10;
            if(temp == 0){
                sumOfSingleDigit += nums[i];
            }
            else{
                sumOfDoubleDigit += nums[i];
            }
        }
    }

    bool canAliceWin(vector<int>& nums) {
        int n = nums.size();
        int sumOfSingleDigit = 0;
        int sumOfDoubleDigit = 0;

        solve(n, nums, sumOfSingleDigit, sumOfDoubleDigit);

        if(sumOfDoubleDigit>sumOfSingleDigit || sumOfDoubleDigit<sumOfSingleDigit){
            return true;
        }   
        else{
            return false;
        }
    }
};