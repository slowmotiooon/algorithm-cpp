#pragma once

#include <string>
using namespace std;

bool backspaceCompare(string s, string t) {
    string s1, t1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '#') {
            if (s1.size()) s1.pop_back();
        }
        else
            s1.push_back(s[i]);
    }
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == '#') {
            if (t1.size()) t1.pop_back();
        }
        else
            t1.push_back(t[i]);
    }
    return s1 == t1;
}

// 通过 | 0ms | 8.19MB
// O(s+t) | O(s+t)