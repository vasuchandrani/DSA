#include<bits/stdc++.h>
using namespace std;

// Brute Force
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

//         int n = gas.size();
//         int startIdx;

//         int i = 0;
//         while (i < n) {
//             startIdx = i;
//             int j = i;
//             int count = 0;
//             int currGas = 0;
//             while (count != n) {
//                 currGas += gas[j];
//                 currGas -= cost[j];
//                 if (currGas < 0) {
//                     break;
//                 }
//                 j++;
//                 j = j % n;
//                 count++;
//             }
//             if (count == n) { 
//                 break;
//             }
//             else {
//                 startIdx = -1;
//             }
//             i++;
//         }     
//         return startIdx; 
//     }
// };Optimal Partition of String


//Greedy
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        int earnSum = 0;
        int costSum = 0;
        for (int kamai : gas) {
            earnSum += kamai;
        }
        for (int kharcha : cost) {
            costSum += kharcha;
        }
        if (costSum > earnSum) {
            return -1;
        }
        //else
            int total = 0;
            int startIdx = 0;
            for (int i=0; i<n; i++) {
                total = total + gas[i] - cost[i];
                if (total < 0) {
                    total = 0;
                    startIdx = i + 1; 
                }
            }

        return startIdx;
    }
};