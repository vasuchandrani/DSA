#include<bits/stdc++.h>
using namespace std;

// with repeatation 
void printStr(string s, vector<char> ch, int idx, int n) {

    if (idx == n) {
        cout<<s;
        return;
    }

    for (int i=0; i<n; i++) {
        s[idx] = ch[i];
        printStr(s, ch, idx+1, n);
    }
}

// without repeatation 
void printStr(string s, vector<bool> used, vector<char> ch, int idx, int n) {

    if (idx == n) {
        cout<<s;
        return;
    }

    for (int i=0; i<n; i++) {
        if (!used[ch[i] - 'a']) {

            s[idx] = ch[i];
            used[ch[i] - 'a'] = true;
            
            printStr(s, used, ch, idx+1, n);

            // backtrck
            used[ch[i] - 'a'] = false; 
        }
    }
} 