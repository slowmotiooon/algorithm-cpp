#pragma once

#include <stack>
#include <string>
using namespace std;

int minLength(string s) {
    stack<char> st;
    for (char c : s) {
        if (!st.empty()) {
            if ((c == 'B' && st.top() == 'A') || (c == 'D' && st.top() == 'C'))
                st.pop();
            else
                st.push(c);
        }
        else
            st.push(c);
    }
    return st.size();
}

// 通过 | 4ms | 11.71MB
// O(n) | O(n)