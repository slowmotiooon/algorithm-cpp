#pragma once

int hammingDistance(int x, int y) {
    return __builtin_popcount(x ^ y);
}

// 通过 | 3ms | 7.43MB
// O(1) | O(1)
// 代码量最少的一集