#pragma once

#include <vector>
using namespace std;

bool doesValidArrayExist(vector<int>& derived) {
    int prev = 0;
    for (int i = 0; i < derived.size() - 1; i++) {
        prev ^= derived[i];
    }
    return prev ^ 0 == derived[derived.size() - 1];
}

// 通过 | 224ms | 257.02MB
// O(n) | O(1)
// 如果derived数组存在original, 那么就会有两个，一个是以0开头的，一个是以1开头的。
// 所以指定开头为1，根据derived数组反推original数组，然后验证original[n-1] ^ 0 是否等于derived[n-1].