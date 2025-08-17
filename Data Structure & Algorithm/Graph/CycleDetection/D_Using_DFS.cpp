// Detect Cycle in Directed graph using DFS

#include<bits/stdc++.h>
using namespace std;

class graph {
public:
    unordered_map<int, vector<int>> adj;

    void addEdges(int u, int v) {
        
        adj[u].push_back(v);
    }
    
    bool isCycleDFS (int node, vector<bool>& visited, vector<bool>& inRecursion) {

        visited[node] = true;
        inRecursion[node] = true;

        for (int &v : adj[node]) {

            if (!visited[v] && isCycleDFS(v, visited, inRecursion)) {
                return true;
            }
            else if (inRecursion[v]) {
                return true;
            }
        }

        inRecursion[node] = false;

        return false;
    }

    bool isCycle(int totalNodes) {

        vector<bool> visited(totalNodes, false);
        vector<bool> inRecursion(totalNodes, false);

        for (int i=0; i<totalNodes; i++) {
            if (!visited[i] && isCycleDFS(i, visited, inRecursion)) 
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
        g.addEdges(u, v);
    }

    if (g.isCycle(n)) {
        cout<<"Graph has cycle"<<endl;
    }
    else {
        cout<<"Graph is cycle less"<<endl;
    }

    return 0;   
}