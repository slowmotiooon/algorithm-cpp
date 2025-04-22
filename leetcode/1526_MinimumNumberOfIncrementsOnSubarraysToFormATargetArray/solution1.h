#pragma once

#include <vector>
using namespace std;

int minNumberOperations(vector<int>& target) {
    int ans = target[0];
    for (int i = 1; i < target.size(); i++) {
        if (target[i] > target[i - 1]) ans += target[i] - target[i - 1];
    }
    return ans;
}

// 通过 | 0ms | 74.17MB | 26:37 | 0x
// O(n) | O(1)
// nb