// DFS
// without using stack

#include<bits/stdc++.h>
using namespace std;

class graph {
public:
    unordered_map<int, vector<int>> adj;

    void addEdges(int u, int v, int dir) {
        // dir - 1 -> directed 
        // dir - 0 -> undirected 

        if (dir) { // directed
            adj[u].push_back(v);
        }
        else { // undirected
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    void dfs(int source, vector<bool>& visited, vector<int>& result) {

        if (visited[source] == true) {
            return;
        }

        visited[source] = true;
        result.push_back(source);

        for (int v : adj[source]) {
            if (!visited[v]) {
                dfs(v, visited, result);
            }
        }
    }
};

int main() {

    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;

    int m;
    cout<<"Enter the number of edges"<<endl;    
    cin>>m;

    cout<<"Directed(1) or Undirected(0) ?? "<<endl;
    int dir;    cin>>dir;

    graph g;
    cout<<"Enter edges {source | destination}"<<endl;
    

    for (int i=0; i<m; i++) {
        int u, v;
        cin>>u>>v;

        g.addEdges(u, v, dir);
    }    
    
    cout<<"Enter source for DFS"<<endl;
    int src; 
    cin>>src;
    vector<int> result;
    vector<bool> visited(n, false);

    g.dfs(src, visited, result);

    for (int i : result) {
        cout<<i<<" ";
    }
    cout<<endl;
  
    return 0;
}


