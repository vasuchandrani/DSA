// Detect Cycle in Directed graph using DFS

#include<bits/stdc++.h>
using namespace std;

class graph {
public:
    unordered_map<int, vector<int>> adj;

    void addEdges(int u, int v) {
        
        adj[u].push_back(v);
    }
    
    bool isCycleBFS (vector<int>& inDegree) {

        int cnt = 0;
        queue<int> q;
        for (int i=0; i<inDegree.size(); i++) {
            if (inDegree[i] == 0) {
                q.push(i);
                cnt++;
            }
        }

        while (!q.empty()) {

            int u = q.front();
            q.pop();
            for (int &v : adj[u]) {

                inDegree[v]--;

                if (inDegree[v] == 0) {
                    q.push(v);
                    cnt++;
                }
            }
        }

        return cnt == inDegree.size();
    }

    bool isCycle(int totalNodes) {

        vector<int> inDegree(totalNodes, 0);
        for (int u=0; u<totalNodes; u++) {

            for (int &v : adj[u]) {
                inDegree[v]++;
            }
        }

        return isCycleBFS(inDegree);
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