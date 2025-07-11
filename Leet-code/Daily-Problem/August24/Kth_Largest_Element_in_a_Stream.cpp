// 12/8/2024

// link = https://leetcode.com/problems/kth-largest-element-in-a-stream/?envType=daily-question&envId=2024-08-12

#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<climits>
using namespace std;

class KthLargest {
public:
    int K;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
         K = k;

        for (int i=0; i<nums.size(); i++) {
            pq.push(nums[i]);

            if(pq.size() > k) {
                pq.pop(); //min element will be poped
            }
        }

    }
    
    int add(int val) {
        pq.push(val);

        if(pq.size() > K) {
            pq.pop();
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */