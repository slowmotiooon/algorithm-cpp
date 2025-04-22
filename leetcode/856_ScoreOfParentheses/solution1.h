#pragma once

#include <stack>
#include <string>
using namespace std;

int scoreOfParentheses(string s) {
    stack<int> st;
    st.push(0);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            st.push(0);
        else {
            if (s[i - 1] == '(') {
                st.pop();
                st.top() += 1;
            }
            else {
                int total = st.top() * 2;
                st.pop();
                st.top() += total;
            }
        }
    }
    return st.top();
}

// 通过 | 0ms | 8.12MB
// O(n) | O(n)
