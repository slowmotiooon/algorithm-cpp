#pragma once

#include <vector>
using namespace std;

int rob(vector<int>& nums) {
    int f = 0, f1 = 0, f2 = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        f = max(f1, f2 + nums[i]);
        f2 = f1;
        f1 = f;
    }
    return f;
}

// 通过 | 0ms | 9.96MB
// O(n) | O(1)