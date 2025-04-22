#pragma once

#include <string>
using namespace std;

bool isValid(string s) {
    string x = "";
    for (char c : s) {
        if (c == '}' || c == ']' || c == ')') {
            if (x.empty())
                return false;
            else if (x.back() == '{' && c != '}')
                return false;
            else if (x.back() == '(' && c != ')')
                return false;
            else if (x.back() == '[' && c != ']')
                return false;
            else { x.pop_back(); }
        }
        else
            x.push_back(c);
    }
    return x.empty();
}

// 通过 | 0ms | 8.55MB
// O(n) | O(n)
