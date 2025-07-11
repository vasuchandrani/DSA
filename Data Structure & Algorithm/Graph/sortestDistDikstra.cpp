// Sortest distance from source node in directed & undirected weighted graph

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Dikstra {
public: 
    unordered_map<int, list<pair<int,int>> > adjList;

    void addEdges(int u, int v, int weight, bool direction) {

        if (direction) {
            pair<int,int> p = make_pair(weight, v);
            adjList[u].push_back(p);
        } else {
            pair<int,int> p1 = make_pair(weight, v);
            adjList[u].push_back(p1);
            pair<int,int> p2 = make_pair(weight, u);
            adjList[v].push_back(p2);
        }
    }

    void printAdjList(){

        for (auto i : adjList) {
            cout<<i.first<<" -> ";
            for (auto j : i.second) {
                cout<<"["<<j.first<<","<<j.second<<"], ";
            }cout<<endl;
        }
    }

    set<pair<int,int>> s;
    //<pair<dist,destinationNode>
    void getSortestPath(int src, vector<bool> &visited, vector<int> &sortestDist) {

        s.insert({src,0});
        while (!s.empty()) {
            
            auto top = *(s.begin());

            int node = top.second;
            int nodeDist = top.first;

            visited[node] = true;
            s.erase(s.begin());

            for (auto i : adjList[node]) {
                if(!visited[i.second]) {
                    s.insert(i);
                }
            }

            for (auto i : adjList[node]) {
                if (sortestDist[i.second] > nodeDist + i.first) {
                    sortestDist[i.second] = nodeDist + i.first;
                }
            }
        }
    }
};

int main () {

    cout<<"enter the number of Nodes:"<<endl;
      int n;  cin>>n;

    cout<<"enter the number of Edges:"<<endl;
    int m;  cin>>m;

    Dikstra d;

    cout<<"Enter 1 if Graph is directed else Enter 0"<<endl;
    bool direction;  cin>>direction;
    
    cout<<"Enter Edges: {sourceNode | destinationNode | weight}"<<endl;
    for (int i=0; i<m; i++) {
        int n1, n2, weight;
        cin >> n1 >> n2 >> weight;
        d.addEdges(n1,n2,weight,direction);
    }
    d.printAdjList();

    vector<int> sortestDist(n, INT_MAX);
    cout<<"Enter Source node: ";
    int src;    cin>>src; 
    sortestDist[src] = 0;

    vector<bool> visited(n, false);
    d.getSortestPath(src,visited,sortestDist);

    cout<<"Sortest Path of all Nodes from Source Node:"<<endl;
    for (int i=0; i<n; i++) {
        cout<<src<<"->"<<i<<" = "<<sortestDist[i]<<endl;
    }cout<<endl;

    return 0;
}