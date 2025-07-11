// 3203
/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    pair<int, int> BFS(unordered_map<int, vector<int>> adj, int src) {
        
        queue<int> q;
        q.push(src);

        unordered_map<int, bool> visited;
        visited[src] = true;

        int dist = 0;
        int farthestNode = src;

        while (!q.empty()) {
            int size = q.size(); // current level nodes

            while (size--) {
                int curr = q.front();
                q.pop();

                farthestNode = curr;
                for (auto &nbr : adj[curr]) {
                    if (!visited[nbr]) {
                        visited[nbr] = true;
                        q.push(nbr);
                    }
                }
            }
            if (!q.empty()) {
                dist++;
            }

            return {farthestNode, dist};
        }

    }


    int findDiameter (unordered_map<int, vector<int>> adj) {

        // step-1: find the farthest node from a random node 
        auto [farthestNode, dist] = BFS(adj, 0);

        // step-2: the farthest node we got is one end of diameter

        // step-3: find the farthest node from that one end which we get from step-1
        auto [otherEndNode, diameter] = BFS(adj, farthestNode);


        return diameter;
    }


    unordered_map<int, vector<int>> AdjList(vector<vector<int>> &edges) {

        unordered_map<int, vector<int>> adj;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        
        unordered_map<int, vector<int>> adj1 = AdjList(edges1);
        unordered_map<int, vector<int>> adj2 = AdjList(edges2);

        int d1 = findDiameter(adj1);
        int d2 = findDiameter(adj2);

        int combinedPath = (d1+1)/2 + (d2+1)/2 + 1;

        return max({d1, d2, combinedPath});

    }
};

*/