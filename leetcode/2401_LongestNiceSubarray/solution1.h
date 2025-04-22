#pragma once

#include <vector>
using namespace std;

int longestNiceSubarray(vector<int>& nums) {
    int sum = 0;
    int left = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        while (sum & nums[i] != 0) {
            sum ^= nums[left];
            left++;
        }
        sum |= nums[i];
        ans = max(ans, i - left + 1);
    }
    return ans;
}

// 通过 | 96ms | 58.46MB
// O(n) | O(1)
// 思路来自：https://leetcode.cn/problems/longest-nice-subarray/solutions/1799426/bao-li-mei-ju-pythonjavacgo-by-endlessch-z6t6
// 十分巧妙的位运算