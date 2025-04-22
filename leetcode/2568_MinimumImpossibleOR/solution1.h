#pragma once

#include <vector>
using namespace std;

int minImpossibleOR(vector<int>& nums) {
    int ans = 0;
    for (int x : nums) {
        if (__builtin_popcount(x) == 1) ans |= x;
    }
    ans = ~ans;
    return 1 << __builtin_ctz(ans);
}

// 通过 | 81ms | 49.04MB
// O(n) | O(1)
// md，我都不知道这是什么原理
// 思路可以看：https://leetcode.cn/problems/minimum-impossible-or/solutions/2119478/nao-jin-ji-zhuan-wan-pythonjavacgo-by-en-7j89