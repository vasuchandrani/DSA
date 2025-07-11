// 27/7/2024
// GRAPH - DSA
/*
You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. 
You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].

You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.
Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.

Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].



Example 1:

Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
Output: 28
Explanation: 
To convert the string "abcd" to string "acbe":
- Change value at index 1 from 'b' to 'c' at a cost of 5.
- Change value at index 2 from 'c' to 'e' at a cost of 1.
- Change value at index 2 from 'e' to 'b' at a cost of 2.
- Change value at index 3 from 'd' to 'e' at a cost of 20.
The total cost incurred is 5 + 1 + 2 + 20 = 28.
It can be shown that this is the minimum possible cost.


Example 2:

Input: source = "aaaa", target = "bbbb", original = ["a","c"], changed = ["c","b"], cost = [1,2]
Output: 12
Explanation: 
To change the character 'a' to 'b' change the character 'a' to 'c' at a cost of 1, 
followed by changing the character 'c' to 'b' at a cost of 2, for a total cost of 1 + 2 = 3. 
To change all occurrences of 'a' to 'b', a total cost of 3 * 4 = 12 is incurred.


Example 3:

Input: source = "abcd", target = "abce", original = ["a"], changed = ["e"], cost = [10000]
Output: -1
Explanation: 
It is impossible to convert source to target because the value at index 3 cannot be changed from 'd' to 'e'.

*/
#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<climits>
using namespace std;


// Floyd warshall algo...
// void FloydWarshall(vector<vector<long long>>& adjMatrix, vector<char>& original, vector<char>& changed, vector<int>& cost, int n){

//     for(int i=0;i<n;i++){
//         int s = original[i] - 'a';
//         int t = changed[i] - 'a';

//         adjMatrix[s][t] = min(adjMatrix[s][t],(long long)cost[i]);
//     }

//     //Apply floyd Warshall
//     for(int k=0;k<26;k++){
//         for(int i=0;i<26;i++){
//             for(int j=0;j<26;j++){
//                 adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
//             }
//         }
//     }
// }

// class Solution {
// public:
//     long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
//         vector<vector<long long>> adjMatrix(26, vector<long long>(26, INT_MAX));
//         int n = source.length();
//         // update adj Matrix with shortest path using Floyd Warshall
//         FloydWarshall(adjMatrix, original, changed, cost, n); 

//         long long ans = 0;
//         for(int i=0; i<n; i++){
//             if(source[i] == target[i]){
//                 continue;
//             }
//             if(adjMatrix[source[i]-'a'][target[i]-'a'] == INT_MAX){
//                 return -1;
//             }

//             ans += adjMatrix[source[i]-'a'][target[i]-'a'];
//         }
//         return ans;
//     }
// };


// // // Dijkstra's algo...

// void dijkstra(char &source, unordered_map<char, vector<pair<char, int>>> adj, vector<vector<long long>> &costMatrix){

//     // min-heap
//     priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;

//     pq.push({0, source});

//     while(!pq.empty()){
//         int d = pq.top().first;
//         char adjNode = pq.top().second;
//         pq.pop();

//         for(auto &it : adj[adjNode]){
//             char adjNode = it.first;
//             int cost = it.second;

//             if(costMatrix[source - 'a'][adjNode - 'a'] > d + cost){
//                 costMatrix[source - 'a'][adjNode - 'a'] = d + cost;
//                 pq.push({d + cost, adjNode});
//             }  
//         }
//         return;
//     }
// }
// class Solution {
// public:
//     long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
//         int n = original.size();
//         unordered_map<char, vector<pair<char,int>>> adj;

//         for(int i=0;i<n;i++){
//             adj[original[i]].push_back({changed[i], cost[i]});
//         }

//         vector<vector<long long>> costMatrix(26, vector<long long>(26, INT_MAX));

//         // Populate the costMatrix using Dijkstra's Algorithm
//         for(int i=0;i<n;i++){
//             char ch = source[i];

//             dijkstra(ch, adj, costMatrix);
//         }

//         long long ans = 0;

//         for(int i=0;i<n;i++){

//             if(source[i] == target[i]){
//                 continue;
//             }
//             if(costMatrix[source[i] - 'a'][target[i] - 'a'] == INT_MAX){
//                 return -1;
//             }

//             ans += costMatrix[source[i] - 'a'][target[i] - 'a'];
//         }
//         return ans;
//     }
// };