#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> rank;
        
    int findParent (int x) {
        if (x == parent[x])
            return x;
        
        return parent[x] = findParent(parent[x]);
    }
    
    void Union(int x, int y) {
        
        int parent_x = findParent(x);
        int parent_y = findParent(y);
        
        if (parent_x == parent_y) return;
        
        if (rank[parent_x] > rank[parent_y]) {
            parent[parent_y] = parent_x;
        }
        else if (rank[parent_y] > rank[parent_x]) {
            parent[parent_x] = parent_y;
        }
        else {
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
    }
        
    int detectCycle(int N, vector<int> adj[]) {
        
        parent.resize(N);
        rank.resize(N);
        
        for (int i=0; i<N; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        
        for (int u=0; u<N; u++) {
        
            for (int &v : adj[u]) {
                
                if (u < v) {
                    
                    int parent_u = findParent(u);
                    int parent_v = findParent(v);
                    
                    if (parent_u == parent_v) return true;
                
                    Union(u, v);
                }
            }
        }
        return false;
    }
};