// creation and implementation of Undirected & weighted GRAPH

#include<bits/stdc++.h>
using namespace std;

class graph {

    public:
        unordered_map<int, vector<pair<int,int>>> adjList;
        void addEdges (int u, int v, int dist) { 

            pair<int, int> P1 = {v, dist};
            adjList[u].push_back(P1);

            pair<int, int> P2= {u, dist};
            adjList[v].push_back(P2);
        }    

        void printAdjList () {
            for(auto i : adjList) {
                cout<< i.first << " -> ";
                for(auto j : i.second) {
                    cout<<"["<<j.first<<", "<<j.second<<"], ";
                }
                cout<<endl;
            }
        }    

        // void DFS (vector<int> &distance, int s, vector<bool> &visited) {

        //     stack<pair<int,int>> st;
        //     st.push(make_pair(s,0));

        //     while (!st.empty()) {

        //         int currNode = st.top().first;
                
        //         st.pop();

        //         // stack ko update kardo...
        //         for (auto x : adjList[currNode]) {
        //             if (!visited[x.first]){
        //                 visited[x.first] = true;
        //                 st.push(x);
        //             }
        //         }

        //         // distance ko bhi update kardo... 
        //         for (auto x : adjList[currNode]) {
        //             if (distance[currNode] + x.second > distance[x.first]) {
        //                 continue;
        //             }
        //             else {
        //                 distance[x.first] = distance[currNode] + x.second; 
        //             }
        //         }

        //         cout<<"currNode = "<<currNode<<endl;
        //         for (int x : distance) {
        //             cout<<x<<" ";
        //         }cout<<endl;
        //     }
        // }
};


int main() {
 
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
 
    int m;
    cout<<"Enter the number of edges"<<endl;    
    cin>>m;

    cout<<"Enter node one by one in the sequence of {sourceNode | destinationNode | distance}"<<endl;
 
    graph g;
    for (int i=0; i<m; i++) {
        int u, v, dist;
        cin>>u>>v>>dist;
 
        // creating an undirected graph
        g.addEdges(u, v, dist);
    }
    g.printAdjList();
 
    // vector<bool> visited(n, false);
    // vector<int> distance(n, 100);
    // cout<< "Enter the source node for DFS"<<endl;
    // int s;
    // cin>>s;
    // distance[s] = 0;
    // g.DFS(distance, s, visited);

    // cout<<"shortest distace of every node from "<<s<<endl;
    // for (int i=0; i<n; i++) {
    //     cout<<distance[i]<<" ";
    // }cout<<endl;
    // return 0;
}