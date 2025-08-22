// Disjoints Union Set
// 2 functions

#include<bits/stdc++.h>
using namespace std;

class DSU {
public: 

    vector<int> parent;

    int findParent(int x) {
        if (parent[x] == x) {
            return x;
        }

        return findParent(parent[x]);
    }

    void Union(int x, int y) {

        int x_parent = findParent(x);
        int y_parent = findParent(y);

        if (x_parent == y_parent) {
            return;
        }

        // make ay one as parent

        parent[y_parent] = x_parent;
    }
};