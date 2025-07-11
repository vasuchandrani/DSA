// 16/10/2024
// link = https://leetcode.com/problems/longest-happy-string/description/?envType=daily-question&envId=2024-10-16

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int, char> P;
    string longestDiverseString(int a, int b, int c) {
        
        priority_queue<P, vector<P>> pq;    // max-heap
        
        if (a > 0) {
            pq.push({a, 'a'});
        }
        if (b > 0) {
            pq.push({b, 'b'});
        }
        if (c > 0) {
            pq.push({c, 'c'});
        }

        string result = "";

        while (!pq.empty()) {
            int currCount = pq.top().first;
            int currChar = pq.top().second;
            pq.pop();

            if (result.length() >= 2 && result[result.length()-1] == currChar && result[result.length()-2] == currChar) {
                // we can't use currChar
                // check for next largest freq char
                if (pq.empty()) {
                    break;
                }

                int nextCount = pq.top().first;
                int nextChar = pq.top().second;
                pq.pop();

                result.push_back(nextChar);
                nextCount--;

                if (nextCount > 0) {
                    pq.push({nextCount, nextChar});
                }
            }
            else {
                result.push_back(currChar);
                currCount--;
            }
            
            if (currCount > 0) {
                pq.push({currCount, currChar});
            }
        }
        return result;
    }
};