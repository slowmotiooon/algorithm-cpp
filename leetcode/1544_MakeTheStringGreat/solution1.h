#pragma once

#include <string>
using namespace std;

string makeGood(string s) {
    string ans = "";
    for (char c : s) {
        if (!ans.empty() && (c - ans.back() == 32 || c - ans.back() == -32))
            ans.pop_back();
        else
            ans.push_back(c);
    }
    return ans;
}

// 通过 | 0ms | 8.36MB
// O(l) | O(l) l指字符串长度