#pragma once

#include <vector>
using namespace std;

vector<int> evenOddBit(int n) {
    vector<int> ans(2, 0);
    for (int i = 0; i < 32; i++) {
        if (n >> i & 1) ans[i % 2]++;
    }
    return ans;
}

// 通过 | 4ms | 9.03MB
// O(32?) | O(1)
// 这算O(1)吗？