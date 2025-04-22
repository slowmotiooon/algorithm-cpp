#pragma once

#include <vector>
using namespace std;

int arithmeticTriplets(vector<int>& nums, int diff) {
    int ans = 0, i = 0, j = 1;
    for (int x : nums) { // x = nums[k]
        while (nums[j] + diff < x)
            ++j;
        if (nums[j] + diff > x)
            continue;
        while (nums[i] + diff * 2 < x)
            ++i;
        if (nums[i] + diff * 2 == x)
            ++ans;
    }
    return ans;
}

// 题解来自：https://leetcode.cn/problems/number-of-arithmetic-triplets/solutions/1728743/by-endlesscheng-mpxt 方法2