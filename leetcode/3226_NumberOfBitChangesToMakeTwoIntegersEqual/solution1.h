#pragma once

#include <bits/stl_algobase.h>
using namespace std;

int minChanges(int n, int k) {
    if (n < k) return -1;
    int mask = 0xffffffff;
    mask = (mask >> (__lg(k) + 1)) << (__lg(k) + 1);
    int a = n & (~mask);
    return ((a & k) != k) ? -1 : __builtin_popcount(n - k);
}

// 通过 | 3ms | 7.78MB
// O(1) | O(1)
// 优化版：
int betterMinChanges(int n, int k) {
    return ((n & k) != k) ? -1 : __builtin_popcount(n - k);
}