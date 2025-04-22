#pragma once

using namespace std;

int hammingWeight(int n) {
    return __builtin_popcount(n);
}

// 通过 | 0ms | 7.78MB
// O(1) | O(1)
// 毫无疑问