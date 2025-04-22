#pragma once

#include <stack>
#include <string>
using namespace std;

string removeDuplicates(string s, int k) {
    string ans = "";
    stack<pair<char, int>> st;
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        if (st.empty() || s[i] != st.top().first) st.push({ s[i], p });
        if (p == ans.size())
            ans.push_back(s[i]);
        else
            ans[p] = s[i];
        if (p - st.top().second == k - 1) {
            p -= k;
            st.pop();
        }
        p++;
    }
    return ans.substr(0, p);
}

// 通过 | 0ms | 14.02MB
// O(n) | O(n)