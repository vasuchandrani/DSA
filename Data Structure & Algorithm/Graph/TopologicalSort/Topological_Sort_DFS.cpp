// u --> v means the order must be [u ,v] in topo sort array,
// so that
// Topo sort only possible in Directed Graph 
// additionally topo sort is only for Acyclic graph, o.w. there was confusion who comes first in order.
// topo sort -> DAG (Directed Acyclic Graph)
// there can be multiple answer of topo sort for same Graph.

// Stack & DFS
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> adj;
    void addEdges(int u, int v) {
        adj[u].push_back(v);
    }
    
    void topoDFS (int u, vector<bool>& vis, stack<int>& st) {
        
        if (vis[u]) return;
            
        vis[u] = true;
        
        for (int &v : adj[u]) {
            if (!vis[v]) {
                topoDFS(v, vis, st);
            }
        } 
        
        st.push(u);
    }
  
    vector<int> topoSort(int N, vector<vector<int>>& edges) {
        
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            
            addEdges(u, v);
        }
        
        stack<int> st;
        vector<bool> vis(N, false);
        
        for (int i=0; i<N; i++) {
            topoDFS(i, vis, st);
        }
        
        vector<int> ans;
        
        while (!st.empty()) {
            int ai = st.top();
            st.pop();
            ans.push_back(ai);
        }
        
        return ans;
    }
};