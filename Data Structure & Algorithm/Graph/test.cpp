#include<bits/stdc++.h>
using namespace std;

//dfs
void dfs (vector<vector<int>> g, vector<bool> visited, int src) {

    visited[src] = true;
    cout<<src<<" ";

    for (int i : g[src]) {

        if (!visited[i]) {
            dfs(g, visited, src);
        }
    }
}

//bfs
void bfs (vector<vector<int>> g, vector<bool> visited, int src) {

    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty()) {

        int cv = q.front();
        cout<<cv<<" ";
        q.pop();

        for (int i : g[cv]) {

            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    } 
}

//multi-stage graph
#define N 5
void multiStage(int G[N][N]) {

    vector<int> minDist(N);
    vector<int> nextNode(N);

    minDist[N-1] = 0;

    for (int i=N-2; i>=0; i--) {
        minDist[i] = INT_MAX;

        for (int j=0; j<N; j++) {
            if(G[i][j] == INT_MAX) 
                continue;
            
            if (minDist[i] > minDist[j] + G[i][j]) {
                minDist[i] = minDist[j] + G[i][j];
                nextNode[i] = j;
            }
        }
    }
}

// nQueen 
bool isSafe(int B[N][N], int r, int c) {

    for (int i=0; i<c; i++) {
        if (B[r][i] == 1) {
            return false;
        }
    }

    for (int i=0, j=0; i<r && j<c; i++, j++) {
        if (B[i][j] == 1) {
            return false;
        }
    }

    for (int i=N, j=0; i>r && j<c; i--, j++) {
        if (B[i][j] == 1) {
            return false;
        }
    }

    return true;
}
bool nQueen(int B[N][N], int col) {

    if (col == N) {
        return true;
    }

    for (int i=0; i<N; i++) { // check for each row; which one is safe

        if (isSafe(B, i, col)) {
            B[i][col] = 1;

            if (nQueen(B, col+1)) {
                return true;
            }
            B[i][col] = 0;
        }
    }

    return false;
}

// knapsack
void knapsack(int i, int cW, int cV, int mV, vector<int> w, vector<int> v, vector<bool> inc, int c, int n) {

    if (i == n) {   // all the items are checked
        if (mV < cV) {
            mV = cV;
        }
        return;
    }

    if (w[i] + cW <= c) {
        cW += w[i];
        cV += v[i];
        inc[i] = true;

        knapsack(i+1, cW, cV, mV, w, v, inc, c, n);
    }

    inc[i] = false;
    knapsack(i+1, cW, cV, mV, w, v, inc, c, n);
}


// graph-coloring 
bool isSafe(vector<vector<int>> g, vector<int> color, int cc, int cv) {

    for (int i : g[cv]) {
        if (color[i] == cc) {
            return false;
        }
    }

    return true;
}
bool colorIt(vector<vector<int>> g, vector<int> color, int m, int cv) {

    if (cv == g.size()) {
        return true;
    }

    for (int cc=0; cc<m; cc++) {
        
        if (isSafe(g, color, cc, cv)) {
            color[cv] = cc;

            if (colorIt(g, color, m, cv+1)) {
                return true;
            }
            color[cv] = 0;
        }
    }

    return false;
}


// hemiltonial cycle
bool isSafe (int G[N][N], int path[], int pos, int cv) {

    for (int i=0; i<N; i++) {
        if (path[i] == cv) {
            return false;
        }
    }

    if (G[path[pos-1]][cv] == -1) {
        return false;
    }

    return true;
}
bool isHcycle (int G[N][N], int path[], int pos) {

    if (pos == N) {
        if (pos > 0 && G[path[pos-1]][path[0]] == 1) {
            return true;
        }
        else {
            return  false;
        }
    }

    for (int cv=1; cv<N; cv++) {

        if (isSafe(G, path, pos, cv)) {
            path[pos] = cv;

            if (isHcycle(G, path, pos)) {
                return true;
            }

            path[pos] = -1;
        }
    }
    return false;
}

// prims algo
int findMinVertex(vector<int> &weights, vector<bool> &visited, int n) {
    int minVertex = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex])) {
            minVertex = i;
        }
    }
    return minVertex;
}
void primsAlgorithm(vector<vector<int>> &graph, int n) {
    vector<int> parent(n, -1);
    vector<int> weights(n, INT_MAX);
    vector<bool> visited(n, false);

    weights[0] = 0; // Start from vertex 0

    for (int i = 0; i < n - 1; i++) {
        int minVertex = findMinVertex(weights, visited, n);
        visited[minVertex] = true;

        for (int j = 0; j < n; j++) {
            if (graph[minVertex][j] != 0 && !visited[j]) {
                if (graph[minVertex][j] < weights[j]) {
                    weights[j] = graph[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }
    for (int i = 1; i < n; i++) {
        cout << "Edge: " << parent[i] << " - " << i << " | Weight: " << graph[i][parent[i]] << endl;
    }
}