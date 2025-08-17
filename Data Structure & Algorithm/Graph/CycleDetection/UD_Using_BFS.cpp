// Detect Cycle in UNdirected graph using BFS

#include<bits/stdc++.h>
using namespace std;

class graph {
public:
    unordered_map<int, vector<int>> adj;

    void addEdges(int u, int v) {
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bool isCycleBFS (int node, int parent, vector<bool>& visited) {

        queue<pair<int, int>> q;
        q.push({node, -1});
        visited[node] = true;


        while (!q.empty()) {

            int u = q.front().first;
            int parent = q.front().second;

            q.pop();

            for (int &v : adj[u]) {

                if (!visited[v]) {
                    visited[v] = true;
                    q.push({v, u});
                }
                else if (v != parent) {
                    return true;
                }
            } 
        } 

        return false;
    }

    bool isCycle(int totalNodes) {

        vector<bool> visited(totalNodes, false);

        for (int i=0; i<totalNodes; i++) {
            if (!visited[i] && isCycleBFS(i, -1, visited)) 
                return true;
        } 

        return false;
    }
};

int main () {
     
    cout<<"Enter number of nodes"<<endl;
    int n;
    cin>>n;
    cout<<"Enter number of edges"<<endl;
    int m;
    cin>>m;

    graph g;

    cout<<"Enter edges {sourceNode | destinationNode}"<<endl;
    for (int i=0; i<m; i++) {
        int u, v;
        cin>>u>>v;
        g.addEdges(u,v);
    }

    if (g.isCycle(n)) {
        cout<<"Graph has cycle"<<endl;
    }
    else {
        cout<<"Graph is cycle less"<<endl;
    }

    return 0;   
}