#pragma once

#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    string t = "";
    for (char c : s) {
        t.push_back(c);
        if (c == 'c') {
            int size = t.size();
            if (size < 3) return false;
            if (t[size - 2] == 'b' && t[size - 3] == 'a') t = t.substr(0, size - 3);
        }
    }
    return t.empty();
}

// 通过 | 31ms | 60.32MB
// O(n*m) | O(n)