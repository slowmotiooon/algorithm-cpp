#pragma once

using namespace std;

int nxor(int n) {
    switch (n % 4) {
    case 3: return 0;
    case 0: return n;
    case 1: return 1;
    default: return n + 1;
    }
}

int xorOperation(int n, int start) {
    return (nxor(start >> 2 - 1) ^ nxor(start >> 2 + n - 1)) * 2 + (start & n & 1);
}

// 通过 | 3ms | 7.30MB
// O(1) | O(1)
// 位运算，题解来自：https://leetcode.cn/problems/xor-operation-in-an-array/solutions/2793723/o1-gong-shi-tui-dao-pythonjavaccgojsrust-le23