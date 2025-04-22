#pragma once

using namespace std;

int minFlips(int a, int b, int c) {
    int y0 = (~c & (a | b)) | (~a & ~b & c);
    int y1 = a & b & ~c;
    return __builtin_popcount(y0) + __builtin_popcount(y1);
}

// 通过 | 0ms | 7.29MB
// O(1) | O(1)
// 思路来自https://leetcode.cn/problems/minimum-flips-to-make-a-or-b-equal-to-c/solutions/101777/huo-yun-suan-de-zui-xiao-fan-zhuan-ci-shu-by-lee-2
// 的评论
// 数电算法，这是真O(1)