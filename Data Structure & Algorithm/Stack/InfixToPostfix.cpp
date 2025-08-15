#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int prec (char c) {
    
    if (c == '^') {
        return 3;
    }
    else if (c == '/' || c == '*') {
        return 2;
    }
    else if (c == '+' || c == '-') {
        return 1;
    }
    else {
        return -1;
    }
}

void postfix(string s) {
    stack<char> st;
    string result;

    int n = s.length();
    for (int i=0; i<n; i++) {
        char c = s[i];
        if ((c >= 'A' && c <= 'Z')) {
            result += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }   st.pop();
        }
        else { 
            while (!st.empty() && prec(s[i]) <= prec(st.top())) {

                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    for (int i=0; i<n; i++) {
        cout<<result[i];
    }cout<<endl;
}

int main() {
    
    string exp = "A+(B*C)-D";
    postfix(exp);

    return 0;
}