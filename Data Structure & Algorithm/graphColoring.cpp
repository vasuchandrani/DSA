#include<bits/stdc++.h>
using namespace std;

bool colorIt (vector<vector<int>> g, vector<int> color, int m, int cV) {

    if (cV == g.size()) {
        return true;
    }

    for (int cC=0; cC<m; cC++) { // check if ith color is safe to paint or not

        if (isSafe(cV, cC, g, color)) {
            color[cV] = cC;
            if (colorIt(g, color, m, cV+1)) {
                return true;
            }
            color[cV] = 0;
        }
    }
    return false;
}

bool isSafe(int cV, int cC, vector<vector<int>> g, vector<int> color) {

    for (auto it : g[cV]) {
        if (color[it] == cC) {
            return false;
        }
    }

    return true;
}