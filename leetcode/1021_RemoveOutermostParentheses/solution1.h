#pragma once

#include <string>
using namespace std;

string removeOuterParentheses(string s) {
    int depth = 0;
    for (auto it = s.begin(); it != s.end();) {
        if (*it == '(') {
            depth++;
            if (depth == 1)
                it = s.erase(it);
            else
                it++;
        }
        else {
            depth--;
            if (depth == 0)
                it = s.erase(it);
            else
                it++;
        }
    }
    return s;
}

// 通过 | 5ms | 8.77MB
// O(n^2) | O(1)
// 空间优化解法，erase操作的时间复杂度是O(n)，因此总时间复杂度是O(n^2)
// 可以另创一个string来存储答案，这样就可以牺牲空间换时间（实际上时间复杂度更优的算法更好）
