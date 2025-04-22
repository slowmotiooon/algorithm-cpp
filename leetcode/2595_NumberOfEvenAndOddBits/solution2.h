#pragma once

#include <vector>
using namespace std;

vector<int> evenOddBit(int n) {
    int mask = 0x5555;
    return { __builtin_popcount(n & mask), __builtin_popcount(n & (mask >> 1)) };
}

// 通过 | 0ms | 8.79MB
// O(1) | O(1)
// 这是真O(1).
// 题解来自：https://leetcode.cn/problems/number-of-even-and-odd-bits/solutions/2177848/er-jin-zhi-ji-ben-cao-zuo-pythonjavacgo-o82o2
// 题解中的方法1和solution1类似，但可以优化为O(log(n))