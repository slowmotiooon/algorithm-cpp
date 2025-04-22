#pragma once

#include <vector>
using namespace std;

vector<int> countBits(int n) {
    vector<int> ans;
    for (int i = 0; i <= n; i++) {
        ans.push_back(__builtin_popcount(i));
    }
    return ans;
}

// 通过 | 8ms | 9.75MB
// O(n) | O(1)
// 内置函数香