// link = https://leetcode.com/problems/construct-string-with-repeat-limit/?envType=daily-question&envId=2024-12-17
// 2182

#include<bits/stdc++.h>
using namespace std;

// not working
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        
        int n = s.length();
        map<char, int> freq_map;

        for (int i=0; i<n; i++) {
            freq_map[s[i]]++;
        } 

        string ans = "";

        while (!freq_map.empty()) {
            auto top = freq_map.rbegin();
            char ch = top->first;
            int freq = top->second;
            freq_map.erase(ch);

            if (ans.empty() || ch != ans.back()) {
                if (freq <= repeatLimit) {
                    for (int i=0; i<freq; i++) {
                        ans.push_back(ch);
                    }
                }
                else {
                    for (int i=0; i<repeatLimit; i++) {
                        ans.push_back(ch);
                        freq--;
                    }
                    if (!freq_map.empty()) {
                        ans.push_back(freq_map.rbegin()->first);
                        freq_map.rbegin()->second -= 1;
                    }
                    freq_map[ch] = freq;
                }    
            }
            else {
                break;
            }
        }
        return ans;
    }
};


// priority queue
/*
class Solution {
public:
    string repeatLimitedString(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        
        priority_queue<pair<char, int>> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) pq.push({'a' + i, freq[i]});
        }
        
        string result;
        while (!pq.empty()) {
            auto [ch, count] = pq.top(); 
            pq.pop();
            int used = min(k, count);
            result.append(used, ch);
            count -= used;

            if (count > 0) {
                if (pq.empty()) break;
                auto [nextCh, nextCount] = pq.top(); 
                pq.pop();
                result += nextCh;
                nextCount--;

                if (nextCount > 0) 
                    pq.push({nextCh, nextCount});
                    
                pq.push({ch, count});
            }
        }
        return result;
    }
};*/