// link = 
// 2558

#include<bits/stdc++.h>
using namespace std;

// approach -1
// Brute force
class Solution {
public:

    int maxIdx(vector<int>& gifts) {

        int n = gifts.size();
        int maxIdx = 0;
        for (int i=1; i<n; i++) {
            
            if (gifts[maxIdx] < gifts[i]) {
                maxIdx = i;
            }
        }
        return maxIdx;
    }

    long long pickGifts(vector<int>& gifts, int k) {
        
        int n = gifts.size();
        for (int i=0; i<k; i++) {

            int m = maxIdx(gifts);
            gifts[m] = sqrt(gifts[m]);
        }

        long long maxGift = 0;
        for (int gift : gifts) {
            maxGift += gift;
        }
        return maxGift;
    }
};

// without max function
class Solution {
public:

    long long pickGifts(vector<int>& gifts, int k) {
        
        int n = gifts.size();
        for (int i=0; i<k; i++) {

            int maxIdx = 0;
            for (int i=1; i<n; i++) {
                if (gifts[maxIdx] < gifts[i]) {
                    maxIdx = i;
                }
            }

            gifts[maxIdx] = sqrt(gifts[maxIdx]);
        }

        long long maxGift = 0;
        for (int gift : gifts) {
            maxGift += gift;
        }

        return maxGift;
    }
};


// approach -2
// priority queue
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {

        int n = gifts.size();
        long long ans = 0;

        priority_queue<int> q;
        for (int &gift : gifts) {
            ans += gift;
            q.push(gift);
        }

        while (k--) {

            int x = q.top();
            q.pop();

            ans = ans - x + sqrt(x);
            q.push(sqrt(x));
        }

        return ans;
    }
};