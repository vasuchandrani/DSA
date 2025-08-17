// creation and implementation of Undirected & Unweighted GRAPH

#include<bits/stdc++.h>
using namespace std;
 
class graph {
public: 
    // Adjacency Matrix
    int adjMat[100][100] = {0};
    void addEdgesMat(int u, int v) {
    
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }
    void printAdjMat(int n) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cout<<adjMat[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    // Adjacency List
    unordered_map<int, vector<int>> adj;
    void addEdgesList(int u, int v) {
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void printAdjList() {
        for(auto i : adj) {
            cout<< i.first << " -> ";
            for(auto j : i.second) {
                cout<< j <<", ";
            }
            cout<<endl;
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
 
    cout<<"Enter edges one by one in the sequence of {sourceNode | destinationNode}"<<endl;

    graph g;

    int adj[100][100] = {0};
    for (int i=0; i<m; i++) {
        int u, v;
        cin>>u>>v;
 
        // add edge in matrix
        g.addEdgesMat(u,v);  

        // add edge in list
        g.addEdgesList(u,v);
    }

    g.printAdjMat(n);   
    
    g.printAdjList();

    return 0;
}
