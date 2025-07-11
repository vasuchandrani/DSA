#include<bits/stdc++.h>
using namespace std;
#define N 5

void printMatrix(int G[N][N]) {
    cout<<endl;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout<<G[i][j]<<" ";
        }cout<<endl;
    }
}

void floyd_warshall(int G[N][N]) {

    for (int k=0; k<N; k++) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (i != j && G[i][k] != 99999 && G[k][j] != 99999 && G[i][j] > G[i][k] + G[k][j]) {
                    G[i][j] = G[i][k] + G[k][j];
                }
            }
        }
        printMatrix(G);
    }
}

int main () {
    
    cout<<"enter matrix of "<<N<<"X"<<N<<endl;
    int G[N][N];
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin>>G[i][j];
        }
    }

    cout<<"Question"<<endl;
    printMatrix(G);
    cout<<endl;
    cout<<"Solutions"<<endl;
    floyd_warshall(G);

    return 0;
}