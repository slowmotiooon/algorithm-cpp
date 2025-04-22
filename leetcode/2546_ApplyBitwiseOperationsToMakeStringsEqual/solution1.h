#pragma once

#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

bool makeStringsEqual(string s, string target) {
    bool count1 = false, count2 = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') count1 = true;
        if (target[i] == '1') count2 = true;
        if (count1 && count2) return true;
    }
    if (!count1 && !count2) return true;
    return false;
}

// 通过 | 25ms | 14.18MB
// O(n) | O(1)