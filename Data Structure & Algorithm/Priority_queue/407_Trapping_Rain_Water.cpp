#include<iostream>
#include<vector> 
#include<string>
#include<math.h>
#include<queue>
#include<utility> // pair
#include<algorithm> // max
#include<functional> // greater<>
using namespace std;

class Solution {
public:
    typedef pair<int, pair<int, int>> PP; // {height, {i, j}}
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int trapRainWater(vector<vector<int>>& hMap) {
        
        int m = hMap.size();
        int n = hMap[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        priority_queue<PP, vector<PP>, greater<>> pq; // min heap

        for (int i=0; i<m; i++) {

            int col[] = {0, n-1};
            for (int j : col) {
                if (!visited[i][j]) {
                    pq.push({ hMap[i][j], { i, j } });
                    visited[i][j] = true;
                }
            }
        }

        for (int j=0; j<n; j++) {

            int row[] = {0, m-1};
            for (int i : row) {
                if (!visited[i][j]) {
                    pq.push({ hMap[i][j], { i, j } });
                    visited[i][j] = true;
                }
            }
        }

        int wtr = 0;

        while (!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            int height = top.first;
            int i = top.second.first;
            int j = top.second.second;

            for (vector<int>& d : dir) {
                int i_ = i + d[0];
                int j_ = j + d[1];

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_]) {
                    
                    wtr += max(height - hMap[i_][j_], 0);

                    pq.push({ max(height, hMap[i_][j_]), { i_, j_ } }); 

                    visited[i_][j_] = true;
                }
            }
        }
        return wtr;
    }
};