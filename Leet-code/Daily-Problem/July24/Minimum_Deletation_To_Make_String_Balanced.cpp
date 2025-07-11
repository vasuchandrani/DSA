// 30/07/2024

/*

You are given a string s consisting only of characters 'a' and 'b'​​​​.

You can delete any number of characters in s to make s balanced. 
s is balanced if there is no pair of indices (i,j) such that 
i < j and s[i] = 'b' and s[j]= 'a'.

Return the minimum number of deletions needed to make s balanced.

Example 1:

Input: s = "aababbab"
Output: 2
Explanation: You can either:
Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").
Example 2:

Input: s = "bbaaaaabb"
Output: 2
Explanation: The only solution is to delete the first two characters.
 
*/

#include<iostream>
#include<vector>
#include<vector>
#include<stack>
#include<climits>
using namespace std;

// By stack
// class Solution {
// public:
//     int minimumDeletions(string s) {

//         int n = s.length();
//         int count = 0;
        
//         stack<char> st;

//         for(int i=0;i<n;i++){
//             // agr 'b' ke baad 'a' aa gya
//             if(!st.empty() && s[i] == 'a' && st.top() == 'b'){
//                 count++;
//                 st.pop();
//             }
//             else{
//                 st.push(s[i]);
//             }
//         }
//         return count;
//     }
// };


// 2nd -approach
// space-complexity O(2n)
// class Solution {
// public:
//     int minimumDeletions(string s) {
//         int n = s.length();

//         vector<int> left_b(n,0);
//         vector<int> right_a(n,0);

//         int countB = 0;
//         for(int i=0;i<n;i++){
//             left_b[i] = countB;
//             if(s[i] == 'b') countB++;
//         }

//         int countA = 0;
//         for(int i=n-1;i>=0;i--){
//             right_a[i] = countA;
//             if(s[i] == 'a') countA++;
//         }
        
//         int deletation = INT_MAX;
//         for(int i=0;i<n;i++){
//             deletation = min(deletation,(left_b[i]+right_a[i]));
//         }

//         return deletation;
//     }
// };


// 3rd -approach
// space-complexity O(n)
// class Solution {
// public:
//     int minimumDeletions(string s) {
//         int n = s.length();

//         vector<int> right_a(n,0);

//         int countA = 0;
//         for(int i=n-1;i>=0;i--){
//             right_a[i] = countA;
//             if(s[i] == 'a') countA++;
//         }
        
//         int deletation = INT_MAX;
//         int countB = 0;
//         for(int i=0;i<n;i++){
//             deletation = min(deletation,(countB + right_a[i]));
//             if(s[i] == 'b') countB++;
//         }
//         return deletation;
//     }
// };


// 4rd -approach
// space-complexity O(1)
// class Solution {
// public:
//     int minimumDeletions(string s) {
//         int n = s.length();

//         int countA = 0;
//         for(int i=n-1;i>=0;i--){
//             if(s[i] == 'a') countA++;
//         }
        
//         int deletation = INT_MAX;
//         int countB = 0;
//         for(int i=0;i<n;i++){
//             if(s[i] == 'a') countA--;
//             deletation = min(deletation,(countB + countA));
//             if(s[i] == 'b') countB++;
//         }
//         return deletation;
//     }
// };

