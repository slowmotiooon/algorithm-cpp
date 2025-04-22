#pragma once

#include <vector>
using namespace std;

int totalHammingDistance(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < 31; i++) {
        int zeros = 0, ones = 0;
        for (int x : nums) {
            if ((x >> i) & 1)
                ones++;
            else
                zeros++;
        }
        ans += zeros * ones;
    }
    return ans;
}

// 通过 | 42ms | 21.18MB
// O(n) | O(1)
// 思路来自：https://leetcode.cn/problems/total-hamming-distance/solutions/799569/gong-shui-san-xie-ying-yong-cheng-fa-yua-g21t
