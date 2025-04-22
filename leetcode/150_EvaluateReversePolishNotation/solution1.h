#pragma once

#include <stack>
#include <string>
#include <vector>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (int i = 0; i < tokens.size(); i++) {
        string s = tokens[i];
        if (s.back() >= '0' && s.back() <= '9') { st.push(stoi(s)); }
        else {
            int operand = st.top();
            st.pop();
            if (s == "+")
                st.top() += operand;
            else if (s == "*")
                st.top() *= operand;
            else if (s == "-")
                st.top() -= operand;
            else if (s == "/")
                st.top() /= operand;
        }
    }
    return st.empty() ? 0 : st.top();
}

// 通过 | 0ms | 16.55MB
// O(n) | O(n)