#pragma once

#include <bits/stl_algobase.h>
using namespace std;

bool hasAlternatingBits(int n) {
    if (n >= 0x80000000) return n == 0xAAAAAAAA;
    int mask = (1 << (__lg(n) + 1));
    if (mask == 0x80000000)
        mask = ~mask;
    else
        mask -= 1;
    int a = ((~n) & mask) << 1;
    return a + (n & 1) == n;
}

// 通过 | 0ms | 7.22MB
// O(1) | O(1)
// n比较大的时候不好处理，需要注意。
// 建议右移

bool betterHasAlternatingBits(int n) {
    long a = n ^ (n >> 1);
    return (a & (a + 1)) == 0;
}

// 题解来自：https://leetcode.cn/problems/binary-number-with-alternating-bits/solutions/1368822/jiao-ti-wei-er-jin-zhi-shu-by-leetcode-s-bmxd
