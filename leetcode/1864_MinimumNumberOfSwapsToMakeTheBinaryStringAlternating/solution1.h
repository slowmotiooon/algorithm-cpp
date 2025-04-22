#pragma once

#include <iostream>
using namespace std;

int minSwaps(string s) {
    int swaps1[2] = { 0, 0 };
    int swaps0[2] = { 0, 0 };
    int t = 1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] - 48 != t)
            swaps1[s[i] - 48]++;
        else
            swaps0[s[i] - 48]++;
        t = t == 0 ? 1 : 0;
    }
    if (swaps1[0] != swaps1[1] && swaps0[0] != swaps0[1])
        return -1;
    else if (swaps1[0] != swaps1[1])
        return swaps0[0];
    else if (swaps0[0] != swaps0[1])
        return swaps1[0];
    else if (swaps1[0] > swaps0[0])
        return swaps0[0];
    else
        return swaps1[0];
}

// 运行结果：
// 通过 | 3ms | 7.93MB
// O(n) | O(1)
// 代码比较直观。