#pragma once

#include <algorithm>
#include <vector>
using namespace std;

int minOperations(vector<int>& nums) {
    int maxVal = *max_element(nums.begin(), nums.end());
    if (maxVal == 0) return 0;
    int operation = __lg(maxVal);
    for (int x : nums) operation += __builtin_popcount(x);
    return operation;
}

// 通过 | 31ms | 27.36MB
// O(n) | O(1)
// 思路来自：https://leetcode.cn/problems/minimum-numbers-of-function-calls-to-make-target-array/solutions/385290/c-shuang-bai-er-jin-zhi-chao-jian-dan-chao-hao-li-