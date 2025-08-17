// u --> v means the order must be [u ,v] in topo sort array,
// so that
// Topo sort only possible in Directed Graph 
// additionally topo sort is only for Acyclic graph, o.w. there was confusion who comes first in order.
// topo sort -> DAG (Directed Acyclic Graph)
// there can be multiple answer of topo sort for same Graph.

// Queue & BFS
// Kahn's Algo

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> adj;
    void addEdges(int u, int v) {
        adj[u].push_back(v);
    }
    
    void topoBFS (vector<int>& inDegree, vector<int>& ans) {
           
        queue<int> q;
        for (int i=0; i<inDegree.size(); i++) {
            if (inDegree[i] == 0) 
                q.push(i);
        }
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            
            for (int &v : adj[u]) {
                    
                inDegree[v]--;
                
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
    }
  
    vector<int> topoSort(int N, vector<vector<int>>& edges) {
        
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            
            addEdges(u, v);
        }
        
        vector<int> inDegree(N, 0);
        for (int u=0; u<N; u++) {
            
            for (int &v : adj[u]) {
                inDegree[v]++;
            }
        }
         
        vector<int> ans;
        topoBFS(inDegree, ans);   
        
        return ans;
    }
};