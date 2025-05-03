#pragma once

#include <vector>
using namespace std;

int maxAbsoluteSum(vector<int>& nums) {
    int maxf = 0, minf = 0, ans = 0;
    int maxv = 0, minv = 0;
    for (int x : nums) {
        maxf = max(maxf + x, x);
        minf = min(minf + x, x);
        maxv = max(maxf, maxv);
        minv = min(minf, minv);
    }
    return max(abs(maxv), abs(minv));
}

// 通过 | 0ms | 44.14MB
// O(n) | O(1)
// 使用动态规划，把绝对值拆分为最大值和最小值就行。