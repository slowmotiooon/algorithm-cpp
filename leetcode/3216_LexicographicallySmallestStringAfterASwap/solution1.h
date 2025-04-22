#pragma once

#include <string>
using namespace std;

string getSmallestString(string s) {
    for (int i = 1; i < s.size(); i++) {
        char x = s[i - 1], y = s[i];
        if (x > y && x % 2 == y % 2) {
            swap(s[i - 1], s[i]);
            break;
        }
    }
    return s;
}

// 通过 | 0ms | 8.02MB
// O(n) | O(1)