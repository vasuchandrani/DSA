#include<bits/stdc++.h>
using namespace std;

class Mono_stack {
public: 

    // nearest larger on left 
    void smallAtLeft(vector<int>& a, vector<int>& ans) {
        stack<int> st;
        
        for (int i=0; i<a.size(); i++) {

            while (!st.empty() && st.top() < a[i]) {
                st.pop();
            }

            if (st.empty()) {
                ans[i] = -1;
            }
            else {
                ans[i] = st.top();
            }
            st.push(a[i]);
        }
    }

    // nearest larger on right
    void smallAtRight(vector<int>& a, vector<int>& ans) {
        stack<int> st;

        for (int i=a.size()-1; i>=0; i--) {

            while (!st.empty() && st.top() < a[i]) {
                st.pop();
            }

            if (st.empty()) {
                ans[i] = -1;
            }
            else {
                ans[i] = st.top();
            }
            st.push(a[i]);
        }
    }
};