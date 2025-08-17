// BFS and DFS for Graph 

#include <bits/stdc++.h>
using namespace std;
class graph {
    public:
        unordered_map<int, list<int>> adjList;

        void addEdges (int u, int v, bool dir) {
            // dir = 1/true -> directed graph
            // dir = 0/false -> undirected graph

            if (dir) {
                adjList[u].push_back(v);
            }
            else {
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }

        void printAdjList () {
            
            for (auto x : adjList) {
                cout<<x.first<<"-> ";
                for (auto y : x.second) {
                    cout<<y<<" ";
                }cout<<endl;
            }
        }

        void BFS(int s, vector<bool> &visited, vector<int> &ans) {

            queue<int> q;
            q.push(s);

            while (!q.empty()) {
                
                int curr = q.front();
                q.pop();
                visited[curr] = true;
                ans.push_back(curr);
                
                for (int x : adjList[curr]) {
                    if (!visited[x]) {
                        visited[x] = true;
                        q.push(x);
                    }
                }
            }
        }

        void DFS (int s, vector<bool> &visited, vector<int> &ans) {

            stack<int> st;
            st.push(s);

            while (!st.empty()) {

                int curr = st.top();
                st.pop();
                visited[curr] = true;
                ans.push_back(curr);

                for (int x : adjList[curr]) {
                    if (!visited[x]) {
                        visited[x] = true;
                        st.push(x);
                    }
                }
            }
        }
};


int main() {

    cout<<"Enter number of nodes"<<endl;
    int n;
    cin>>n;
    cout<<"Enter number of edges"<<endl;
    int m;
    cin>>m;

    cout<<"Enter 1 if graph is directed else Enter 0"<<endl;
    bool dir;
    cin>>dir;

    graph g;

    cout<<"Enter edges {sourceNode | destinationNode}"<<endl;
    for (int i=0; i<m; i++) {
        int u, v;
        cin>>u>>v;
        g.addEdges(u,v,dir);
    }

    cout<<"Adj-List"<<endl;
    g.printAdjList();
    
    cout<<"Enter the sourceNode for BFS traversal"<<endl;
    int src;    
    cin>>src;
    
    vector<bool> bfsVisited;
    vector<int> ansBFS;
    g.BFS(src,bfsVisited,ansBFS);

    cout<<"BFS Traversal"<<endl;
    for (int x : ansBFS) {
        cout<<x<<" ";
    }cout<<endl;

    cout<<"Enter the sourceNode for DFS traversal"<<endl;
    int s;    
    cin>>s;
    
    vector<bool> dfsVisited;
    vector<int> ansDFS;
    g.DFS(s,dfsVisited,ansDFS);
    
    cout<<"DFS Traversal"<<endl;
    for (int x : ansDFS) {
        cout<<x<<" ";
    }cout<<endl;

    return 0;
}


