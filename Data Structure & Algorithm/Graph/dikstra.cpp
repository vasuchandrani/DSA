#include<bits/stdc++.h>
using namespace std;
#define N 9

int g[N][N];

void addEdge (int u, int v, int w) {
    
    g[u][v] = w;
    g[v][u] = w;
}

void printMat (int g[][N]) {
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout<<g[i][j]<<" ";
        }cout<<endl;
    }
}

int findMinDist(vector<int> minDist, vector<bool> visited) {

    int mini = INT_MAX;
    int minIdx = -1;
    for (int i=0; i<N; i++) {
        if (!visited[i] && mini > minDist[i]) {
            mini = minDist[i];
            minIdx = i;
        }
    }

    return minIdx;
}

int cnt = 0;
void dikstra(int g[][N], int s) {

    vector<int> minDist(N, INT_MAX);
    vector<bool> visited(N, false);

    minDist[s] = 0;

    for (int i=0; i<N-1; i++) {
        int cv = findMinDist(minDist, visited);
        visited[cv] = true;

        for (int iv=0; iv<N; iv++) {
            if (!visited[iv] && g[cv][iv] != -1 && minDist[cv] + g[cv][iv] < minDist[iv]) {
                minDist[iv] = minDist[cv] + g[cv][iv];
            }
        }
    }    


    cout<<"Dist. from scr "<<s<<":"<<endl;
    for (int i=0; i<N; i++) {
        cout<<s<<" to "<<i<<" "<<minDist[i]<<endl;
    }
}

int main() {

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            g[i][j] = -1;
        }
    }

    addEdge(1, 2, 8);
    addEdge(1, 0, 4);
    addEdge(1, 7, 11);
    addEdge(0, 7, 8);
    addEdge(8, 7, 7);
    addEdge(7, 6, 1);
    addEdge(8, 6, 6);
    addEdge(2, 8, 2);
    addEdge(3, 2, 7);
    addEdge(5, 2, 4);
    addEdge(6, 5, 2);
    addEdge(3, 5, 14);
    addEdge(3, 4, 9);
    addEdge(5, 4, 10);

    cout<<endl;
    cout<<"minimum distance from all the vertax"<<endl;
    for (int i=0; i<N; i++) {
        dikstra(g,i);
    }
    // dikstra(g, 0);
}