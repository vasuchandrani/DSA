// link = 
// 1792

#include<bits/stdc++.h>
using namespace std;

// wrong approach
class Solution {
public:
    #define P pair<double, pair<int, int>>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        priority_queue<P, vector<P>, greater<P>> q;

        for (auto vec : classes) {

            double avg = (double)vec[0]/vec[1];
            q.push({avg, {vec[0], vec[1]}});
        }      

        // while (!q.empty()) {
        //     cout<<q.top().first<<"-> "<<q.top().second.first<<","<<q.top().second.second<<endl;
        //     q.pop();
        // }

        while (extraStudents--) {

            auto minAvg = q.top();

            int pass = minAvg.second.first;
            int total = minAvg.second.second;
            
            q.pop();

            pass++;
            total++;

            int newAvg = (double) pass / total; 
            q.push({newAvg, {pass, total}});
        }

        int class_cnt = 0;
        double total_avg = 0;
        while (!q.empty()) {

            total_avg += q.top().first;
            class_cnt++;
            q.pop();
        }

        return total_avg/class_cnt;
    }
};

// time limit exeed
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        int n = classes.size();

        vector<double> PR(n);
        for (int i=0; i<n; i++) {
            double ratio = (double)classes[i][0]/ classes[i][1];
            PR[i] = ratio;
        }

        while (extraStudents--) {

            vector<double> updtPR(n);
            for (int i=0; i<n; i++) {
                double newRatio = (double)(classes[i][0]+1)/(classes[i][1]+1);
                updtPR[i] = newRatio;
            }

            int Idx = 0;
            double bestDelta = 0.0;
        
            for (int i=0; i<n; i++) {
                double delta = updtPR[i] - PR[i];
                if (delta > bestDelta) {
                    bestDelta = delta;
                    Idx = i;
                }
            }

            PR[Idx] = updtPR[Idx];
            classes[Idx][0]++;
            classes[Idx][1]++;

        }

        double result = 0.0;

        for (int i=0; i<n; i++) {
            result += PR[i];
        }

        return result/n;
    }
};

// max-heap
// correct
class Solution {
public:
    #define P pair<double, int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        int n = classes.size();

        priority_queue<P> q;

        for (int i=0; i<n; i++) {
            
            double currPR = (double)classes[i][0]/ classes[i][1];
            double newPR = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double delta = newPR - currPR;
            q.push({delta, i});
        }

        while (extraStudents--) {

            auto curr = q.top();
            q.pop();

            double delta = curr.first;
            int idx = curr.second;

            classes[idx][0]++;
            classes[idx][1]++;

            double currPR = (double)classes[idx][0]/ classes[idx][1];
            double newPR = (double)(classes[idx][0]+1)/(classes[idx][1]+1);
            delta = newPR - currPR;
            q.push({delta, idx});
        }

        double result = 0.0;

        for (int i=0; i<n; i++) {
            result += (double)classes[i][0]/ classes[i][1];;
        }

        return result/n;
    }
};