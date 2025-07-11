#include<bits/stdc++.h>
using namespace std;
#define N 4
int cnt = 0;

void cleanBoard(int B[N][N]) {

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            B[i][j] = 0;
        }
    }
}

void printSolution(int B[N][N]) {

    for (int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout<<B[i][j]<<" ";
        }cout<<endl;
    }
    cout<<endl;
}

bool isSafe(int B[N][N], int r, int c) {

    for (int i=0; i<c; i++) {   // horizontaly 
        if (B[r][i] == 1) {
            return false;
        }
    }

    for (int i=r, j=c; i>=0 && j>=0; i--, j--) { // upper-left 
        if (B[i][j] == 1) {
            return false;
        }
    }

    for (int i=r, j=c; i<N && j>=0; i++, j--) { // lower-left
        if (B[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool nQueen(int B[N][N], int col) {

    if (col >= N) {
        cnt++;
        cout<<"solution no. "<<cnt<<endl;
        printSolution(B);
        return true;
    }

    for (int i=0; i<N; i++) { // row
        if (isSafe(B, i, col)) { // col
            B[i][col] = 1;

            nQueen(B, col+1);

            // backtracking 
            B[i][col] = 0;
        }
    }

    
    return false;
}

int main() {
    int B[N][N];
    cleanBoard(B);

    nQueen(B, 0);

    if (cnt == 0) {
        cout << "Solution is not possible for " << N << " queens" << endl;
    } else {
        cout << "Total solutions found: " << cnt << endl;
    }

    return 0;
}