#pragma once

using namespace std;

int minimizeXor(int num1, int num2) {
    int c1 = __builtin_popcount(num1);
    int c2 = __builtin_popcount(num2);
    for (; c2 < c1; ++c2) num1 &= num1 - 1;   // 最低的 1 变成 0
    for (; c2 > c1; --c2) num1 |= num1 + 1;   // 最低的 0 变成 1
    return num1;
}

// 题解来自：https://leetcode.cn/problems/minimize-xor/solutions/1864059/o1-kong-jian-fu-za-du-zuo-fa-by-endlessc-ywio
// 优雅。