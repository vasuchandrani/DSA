// creation and implementation of Directed & weighted GRAPH

#include<bits/stdc++.h>
using namespace std;

class graph {
    public:
        unordered_map<int, list<pair<int,int>>> adjList;
        void addEdges (int u, int v, int dist) { 
            // add edge u --> v 

            pair<int, int> P1 = {v, dist};
            adjList[u].push_back(P1);
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
 
        g.addEdges(u, v, dist);
    }
    g.printAdjList();

    return 0;
}