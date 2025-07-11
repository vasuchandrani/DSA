#include<bits/stdc++.h>
using namespace std;
#define N 5

void multtiStage(int G[N][N]) {
    
    vector<int> minDist(N);
    vector<int> nextNode(N);

    minDist[N-1] = 0;

    for (int i=N-2; i>=0; i--) {
        minDist[i] = INT_MAX;

        for (int j=0; j<N; j++) {
            if (G[i][j] == INT_MAX) {
                continue;
            }

            if (minDist[i] > G[i][j] + minDist[j]) {
                minDist[i] = G[i][j] + minDist[j];
                nextNode[i] = j;
            }
        }
    }
}