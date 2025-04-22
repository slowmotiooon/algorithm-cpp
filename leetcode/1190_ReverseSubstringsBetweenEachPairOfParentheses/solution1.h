#pragma once

#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

string reverseParentheses(string s) {
    int n = s.size();
    stack<int> st;
    unordered_map<int, int> go;
    string ans = "";
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') st.push(i);
        if (s[i] == ')') {
            go[st.top()] = i;
            go[i] = st.top();
            st.pop();
        }
    }
    bool front = true;
    for (int i = 0; i != s.size();) {
        if (s[i] == '(' || s[i] == ')') {
            i = go[i];
            front = !front;
        }
        else { ans.push_back(s[i]); }
        i += (front ? 1 : -1);
    }
    return ans;
}

// 通过 | 0ms | 8.65MB
// O(n) | O(n)
// 思路来自：https://leetcode.cn/problems/reverse-substrings-between-each-pair-of-parentheses/solutions/795515/fan-zhuan-mei-dui-gua-hao-jian-de-zi-chu-gwpv
// 方法二