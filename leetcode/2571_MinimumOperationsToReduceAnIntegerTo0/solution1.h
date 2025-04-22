#pragma once

using namespace std;

int minOperations(int n) {
    return __builtin_popcount(n ^ (3 * n));
}

// 通过 | 0ms | 7.31MB
// O(1) | O(1)
// 题解来自：https://leetcode.cn/problems/minimum-operations-to-reduce-an-integer-to-0/solutions/2120204/ji-yi-hua-sou-suo-by-endlesscheng-cm6l