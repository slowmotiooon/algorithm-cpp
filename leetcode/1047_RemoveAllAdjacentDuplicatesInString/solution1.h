#pragma once

#include <string>
using namespace std;

string removeDuplicates(string s) {
    string ans = "";
    for (char c : s) {
        if (!ans.empty() && c == ans.back())
            ans.pop_back();
        else
            ans.push_back(c);
    }
    return ans;
}

// 通过 | 4ms | 13.44MB
// O(l) | O(l) l指字符串长度
