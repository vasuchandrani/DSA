// 1/10/2024
// link = https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/?envType=daily-question&envId=2024-10-01

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {

        vector<int> v(k, 0);
        // v[r] = x where r(remainder) has freq x;

        for (int &num : arr) {
            int rem = (num % k + k) % k;  //handling negative remainders
 
            v[rem]++;
        }

        if (v[0]%2 != 0) {
            return false;
        }

        for (int rem=1; rem<=k/2; rem++) {

            int counterHalf = k - rem;
            if (v[counterHalf] != v[rem]) {
                return false;
            }
        }
        return true;
    }
};