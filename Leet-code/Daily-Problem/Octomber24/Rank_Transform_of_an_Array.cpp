// 2/10/2024 
// link = https://leetcode.com/problems/rank-transform-of-an-array/?envType=daily-question&envId=2024-10-02

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        map<int, int> vecRank;
        
        vector<int> SortedArr(arr);
        sort(SortedArr.begin(), SortedArr.end());
        
        int rank = 1;
        for(int i=0; i<SortedArr.size(); i++){
            if(i>0 && SortedArr[i]> SortedArr[i-1]){
                rank++;
            }
            vecRank[SortedArr[i]]=rank;
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=vecRank[arr[i]];
        }
        return arr;
    }
};