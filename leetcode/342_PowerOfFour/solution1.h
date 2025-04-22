#pragma once

#include <bits/stl_algobase.h>
using namespace std;

bool isPowerOfFour(int n) {
    if (n <= 0) return false;
    return ((__lg(n) & 1) == 0) && (__builtin_popcount(n) == 1);
}

// 通过 | 0ms | 7.31MB
// O(1) | O(1)
// 利用了4的幂的两个特点：
//  1. 二进制长度为奇数，即(__lg(n)&1)==0
//  2. 整个二进制数只有一个1，即__builtin_popcount(n)==1
// __lg(n) 在g++上过不了，不知道为什么。
// 追加：使用__lg需要 #include <bits/stl_algobase.h>