// Disjoints Union Set - Optimised with Rank and Path Compression. 
// 2 functions

#include<bits/stdc++.h>
using namespace std;

class DSU {
public: 

    vector<int> parent;
    vector<int> rank;

    int findParent(int x) {
        if (parent[x] == x) {
            return x;
        }

        return parent[x] = findParent(parent[x]);
    }

    void Union(int x, int y) {

        int x_parent = findParent(x);
        int y_parent = findParent(y);

        if (x_parent == y_parent) {
            return;
        }

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        }
        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
};