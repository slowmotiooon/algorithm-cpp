#pragma once

#include <stack>
#include <string>
using namespace std;

string minRemoveToMakeValid(string s) {
    stack<string::iterator> brackets;
    for (auto it = s.begin(); it != s.end();) {
        if (*it == '(') brackets.push(it);
        if (*it == ')') {
            if (brackets.empty())
                it = s.erase(it);
            else {
                brackets.pop();
                it++;
            }
        }
        else
            it++;
    }
    while (!brackets.empty()) {
        s.erase(brackets.top());
        brackets.pop();
    }
    return s;
}

// 通过 | 11ms | 13.51MB
// O(n) | 13.51MB