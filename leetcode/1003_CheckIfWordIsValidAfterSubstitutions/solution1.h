#pragma once

#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    string t = "";
    for (char c : s) {
        t.push_back(c);
        if (c == 'c') {
            if (t.size() < 3) return false;
            if (t.find("abc") != string::npos) t = t.substr(0, t.size() - 3);
        }
    }
    return t.empty();
}

// 通过 | 861ms | 60.45MB
// O(n^2) | O(n)
// 可能是因为find函数比较消耗时间复杂度。