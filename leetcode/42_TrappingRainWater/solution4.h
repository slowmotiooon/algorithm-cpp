#pragma once

#include <vector>
using namespace std;

int trap(vector<int>& height) {
    int ans = 0, left = 0, right = height.size() - 1, pre_max = 0, suf_max = 0;
    while (left < right) {
        pre_max = max(pre_max, height[left]);
        suf_max = max(suf_max, height[right]);
        ans += pre_max < suf_max ? pre_max - height[left++] : suf_max - height[right--];
    }
    return ans;
}

// 题解来源：https://leetcode.cn/problems/trapping-rain-water/solutions/1974340/zuo-liao-nbian-huan-bu-hui-yi-ge-shi-pin-ukwm 方法二
// 使用相向双指针，相当于 solution2 的优化版，十分优雅。