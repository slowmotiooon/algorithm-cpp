#pragma once

using namespace std;

bool isPowerOfFour(int n) {
    if (n <= 0) return false;
    int mask = 0x55555555;
    return ((n & (n - 1)) == 0) && ((n & mask) != 0);
}

// 通过 | 0ms | 7.30MB
// O(1) | O(1)
// 思路来自：https://leetcode.cn/problems/power-of-four/solutions/798268/4de-mi-by-leetcode-solution-b3ya
// 先判断n是否为2的幂 (n & (n - 1)) == 0)，然后再通过使其与
// 0b 0101 0101 0101 0101 0101 0101 0101 0101 (0x55555555)进行按位与，验证是否为4的幂