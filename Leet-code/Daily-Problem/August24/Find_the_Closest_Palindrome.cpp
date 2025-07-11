// 24/08/2024
// link - https://leetcode.com/problems/find-the-closest-palindrome/?envType=daily-question&envId=2024-08-24

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    long func(long fisrtHalf, bool isEven) {
        
        long resultNum = fisrtHalf;
        if (isEven == false) {
            fisrtHalf /= 10;
        }

        while(fisrtHalf > 0) {
            int digit = fisrtHalf % 10;
            resultNum = (resultNum * 10) + digit;
        
            fisrtHalf /= 10;
        }
        return resultNum;
    }

    string nearestPalindromic(string n) {
        int L = n.length();

        int mid = L/2;

        int firstHalfLength = (L%2 == 0) ? mid : (mid + 1);

        long firstHalf = stol(n.substr(0, firstHalfLength));
    
        vector<long> possibleResults;        

        possibleResults.push_back(func(firstHalf, L%2 == 0));
        possibleResults.push_back(func(firstHalf+1  , L%2 == 0));
        possibleResults.push_back(func(firstHalf-1, L%2 == 0));
        possibleResults.push_back((long)pow(10, L-1) - 1);
        possibleResults.push_back((long)pow(10, L) + 1);
    
        long diff = LONG_MAX;
        long result = LONG_MAX;
        long Original = stol(n);

        for (long num : possibleResults) {

            if (num == Original) {
                continue;
            }
            if (abs(num - Original) < diff) {
                diff = abs(num - Original);
                result = num;
            }   
            else if (abs(num - Original) == diff) {
                result = min(result, num); 
            }
        }
        return to_string(result);
    }
};
