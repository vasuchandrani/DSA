#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> rank; 

    int find (int x) {
        if (x == parent[x]) return x;

        return parent[x] = find(parent[x]);
    }

    void Union (int x, int y) {

        int x_parent = find(x);
        int y_parent = find(y);

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

    bool equationsPossible(vector<string>& eq) {
        
        parent.resize(26);
        rank.resize(26, 0);

        for (int i=0; i<26; i++) {
            parent[i] = i;
        }

        for (string &s : eq) {
            
            int x_parent = find(s[0] - 'a');
            int y_parent = find(s[3] - 'a');

            if (s[1] == '=') {

                Union(x_parent, y_parent);
            }
        }

        for (string &s : eq) {

            int x_parent = find(s[0] - 'a');
            int y_parent = find(s[3] - 'a');
            
            if (s[1] == '!') {

                if (x_parent == y_parent) {
                    return false;
                }
            }
        }

        return true;
    }
};