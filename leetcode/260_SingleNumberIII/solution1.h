#pragma once

#include <vector>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    unsigned int xor_ = 0;
    for (int x : nums) xor_ ^= x;

    xor_ = xor_ & -xor_;

    int xor1 = 0, xor2 = 0;
    for (int x : nums) {
        if ((x & xor_) == xor_)
            xor1 ^= x;
        else
            xor2 ^= x;
    }
    return { xor1, xor2 };
}

// 通过 | 7ms | 12.35MB
// O(n) | O(1)
// 思路来自：https://leetcode.cn/problems/single-number-iii/solutions/2484352/tu-jie-yi-zhang-tu-miao-dong-zhuan-huan-np9d2
// xor_使用unsigned int是因为如果最后的xor_是-2147483648的话，会在第10行导致int溢出。