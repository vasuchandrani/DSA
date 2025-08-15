// backtracking
#include<bits/stdc++.h>
using namespace std;

void printSolution (int maxValue, vector<vector<int>> &solutions) {

    
    cout<<"max value of knapsack is : "<<maxValue<<endl;

    cout<<"Possible solutions"<<endl;
    for (auto solution : solutions) {
        for (auto value : solution) {
            cout<<value<<" ";
        }
        cout << endl;
    }
}

void knapsack (int i, int cw, int cv, int &maxValue, vector<int> &w, vector<int> &v, vector<vector<int>> &solutions, vector<int> &inc, int c, int n) {

    if (i == n) {

        if (maxValue < cv) {
            maxValue = cv;
            solutions.clear();
            solutions.push_back(inc);
        } 
        else if (maxValue == cv) {
            solutions.push_back(inc);
        }
        return;
    }

    if (cw + w[i] <= c) {
        inc[i] = 1;
        knapsack(i+1, cw+ w[i], cv+ v[i], maxValue, w, v, solutions, inc, c, n);
    }

    inc[i] = 0;
    knapsack(i+1, cw, cv, maxValue, w, v, solutions, inc, c, n);
    
}

int main () {

    int n;
    cout<<"enter size :";
    cin>>n;

    vector<int> w(n);
    vector<int> v(n);

    cout<<"enter wieght arry"<<endl;
    for (int i=0; i<n; i++) {
        cin>>w[i];
    }
    cout<<"enter value arry"<<endl;
    for (int i=0; i<n; i++) {
        cin>>v[i];
    }

    cout<<"enter the capacity of knapsack"<<endl;
    int c;  cin>>c;

    int maxValue = 0;
    vector<int> inc(n, 0);
    vector<vector<int>> solutions;

    knapsack(0, 0, 0, maxValue, w, v, solutions, inc, c, n);

    printSolution(maxValue, solutions);
}