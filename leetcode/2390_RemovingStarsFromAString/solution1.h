#pragma once

#include <string>
#include <vector>
using namespace std;

string removeStars(string s) {
    string ans;
    for (char c : s) {
        if (c == '*')
            ans.pop_back();
        else
            ans.push_back(c);
    }
    return ans;
}

// 通过 | 23ms | 27.94MB | 1:34 | 0x
// O(n) | O(n)