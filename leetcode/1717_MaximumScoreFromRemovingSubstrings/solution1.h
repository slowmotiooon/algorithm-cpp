#pragma once

#include <string>
using namespace std;

int maximumGain(string s, int x, int y) {
    char p = x > y ? 'b' : 'a';
    char t = x <= y ? 'b' : 'a';
    int score = 0;
    string ans = "", buf = "";
    for (char c : s) {
        if (!buf.empty() && buf.back() == t && c == p) {
            buf.pop_back();
            score += max(x, y);
        }
        else
            buf.push_back(c);
    }
    for (char c : buf) {
        if (!ans.empty() && ans.back() == p && c == t) {
            ans.pop_back();
            score += min(x, y);
        }
        else
            ans.push_back(c);
    }
    return score;
}

// 通过 | 19ms | 26.88MB
// O(n) | O(n)