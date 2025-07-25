#include<bits/stdc++.h>
using namespace std;

void dfs(int vertax, int parent, unordered_map<int, vector<int>> &G, vector<int> &passengers, int &bus) {
    for (int node : G[vertax]) {
        if (node != parent) {
            dfs(node, vertax, G, passengers, bus);
            passengers[vertax] += passengers[node];
        }
    }
    if (vertax != 1 && passengers[vertax] > 0) {
        bus++;
    }
}

int solve(int N, vector<int> &Passengers, vector<vector<int>> &Edges) {

    unordered_map<int, vector<int>> G;
    for (auto edge : Edges) {
        G[edge[0]].push_back(edge[1]);
        G[edge[1]].push_back(edge[0]);
    }
    
    vector<int> passengers(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        passengers[i] = Passengers[i - 1];
    }
    
    int bus = 0;
    dfs(1, -1, G, passengers, bus);
    return bus;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++) {
        int N;
        cin >> N;
        vector<int> Passengers(N);
        for (int i_Passengers = 0; i_Passengers < N; i_Passengers++) {
            cin >> Passengers[i_Passengers];
        }
        vector<vector<int>> Edges(N-1, vector<int>(2)); 
        for (int i_Edges = 0; i_Edges < N-1; i_Edges++) {
            for (int j_Edges = 0; j_Edges < 2; j_Edges++) {
                cin >> Edges[i_Edges][j_Edges];
            }
        }
        int out_;
        out_ = solve(N, Passengers, Edges);
        cout << out_;
        cout << "\n";
    }
    return 0;
}