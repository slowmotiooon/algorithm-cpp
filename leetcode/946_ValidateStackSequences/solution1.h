#pragma once

#include <stack>
#include <vector>
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int pot = 0;
    stack<int> st;
    for (int x : pushed) {
        st.push(x);
        while (!st.empty() && st.top() == popped[pot]) {
            st.pop();
            pot++;
        }
    }
    return st.empty();
}

// 通过 | 0ms | 18.64MB
// O(n) | O(1)