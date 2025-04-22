#pragma once

#include <string>
using namespace std;

int minAddToMakeValid(string s) {
    string a = "";
    for (char c : s) {
        if (!a.empty() && a.back() == '(' && c == ')')
            a.pop_back();
        else
            a.push_back(c);
    }
    return a.size();
}

// 通过 | 0ms | 8.47MB
// O(n) | O(n)
