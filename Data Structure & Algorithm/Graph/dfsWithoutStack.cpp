// DFS
// without using stack

#include<bits/stdc++.h>
using namespace std;

class graph {

    public:
    void dfs(int node, unordered_map<int,bool> &visited, unordered_map<int, list<int>> &adjList, vector<int> &component) {

        component.push_back(node);
        visited[node] = true;
         
        for (auto i : adjList[node]) {
            if (!visited[i]) {
                dfs(i, visited, adjList, component);
            }
        }
    }

    void depthFirstSearch(int V, vector<vector<int>> &edges, vector<vector<int>> &ans) {
        // V == no. of nodes
        // E == no. of edges

        // prepare Adj-List: 
        unordered_map<int, list<int>> adjList;
        int size = edges.size();
        for (int i=0; i<size; i++) {
            
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }


        // call DFS for each node:
        unordered_map<int,bool> visited;
        for (int i=0; i<V; i++) {
            if(!visited[i]) {
                vector<int> component;
                dfs(i, visited, adjList, component);
                ans.push_back(component);
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

    graph g;
    
    vector<vector<int>> edges;
    for (int i=0; i<m; i++) {

        int n1, n2;
        cin>>n1>>n2;
        edges.push_back({n1, n2});
    }    
    
    vector<vector<int>> ans;
    g.depthFirstSearch(n,edges,ans);

    int size = ans.size();
    for (int i = 0; i < size; i++) {
        int innerSize = ans[i].size();
        for (int j = 0; j < innerSize; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


