// 769

#include<bits/stdc++.h>
using namespace std;

// approach -1
// prefix & suffix 
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        int n = arr.size();
        vector<int> prefixMax(arr.begin(), arr.end());
        vector<int> suffixMin(arr.begin(), arr.end());

        for (int i=1; i<n; i++) {
            prefixMax[i] = max(prefixMax[i], prefixMax[i-1]);
        }

        for (int i=n-2; i>=0; i--) {
            suffixMin[i] = min(suffixMin[i], suffixMin[i+1]);
        }

        int cnt = 0;
        for (int i=0; i<n; i++) {
            
            int pehleKaMax = i > 0 ? prefixMax[i-1] : -1;
            int baadKaMin = suffixMin[i];

            if (pehleKaMax < baadKaMin) {
                cnt++;
            }
        }

        return cnt;
    }
};


// approach -2
// we know the sorted arry
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int n = arr.size();

        int cumSum = 0;
        int originalSum = 0;

        int cnt = 0;
        for (int i=0; i<n; i++) {
            cumSum += arr[i];

            originalSum += i;

            if (cumSum == originalSum) {
                cnt++;
            }
        }

        return cnt;
    }
};


// approach -3
// idx and value of ele both are same in sorted array
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int n = arr.size();
        int maxTillNow = -1;

        int cnt = 0;
        for (int i=0; i<n; i++) {
            maxTillNow = max(maxTillNow, arr[i]);

            if (maxTillNow == i) {
                cnt++;
            }
        }

        return cnt;
    }
};