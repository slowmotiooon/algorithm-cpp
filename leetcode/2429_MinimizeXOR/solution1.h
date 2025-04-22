#pragma once

#include <bits/stl_algobase.h>
using namespace std;

int minimizeXor(int num1, int num2) {
    int bp1 = __builtin_popcount(num1);
    int bp2 = __builtin_popcount(num2);

    if (bp1 == bp2)
        return num1;
    else if (bp1 < bp2) {
        int ans = num1;
        for (int i = 0; i < bp2 - bp1; i++) {
            ans ^= (1 << __builtin_ctz(~ans));
        }
        return ans;
    }
    else {
        int ans = num1;
        for (int i = 0; i < bp2; i++) {
            ans ^= (1 << __lg(ans));
        }
        return ans ^ num1;
    }
}

// 通过 | 4ms | 7.51MB
// O(log(n)) | O(1)