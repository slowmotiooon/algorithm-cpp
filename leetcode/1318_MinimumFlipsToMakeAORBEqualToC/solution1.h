#pragma once

#include <bitset>
using namespace std;

int minFlips(int a, int b, int c) {
    bitset<32> x(a), y(b), z(c);
    int ans = 0;

    for (int i = 0; i < 32; i++) {
        if (z[i] && !x[i] && !y[i]) ans++;
        if (!z[i]) {
            if (x[i]) ans++;
            if (y[i]) ans++;
        }
    }
    return ans;
}

// 通过 | 0ms | 7.33MB
// O(1) | O(1)
// 活用bitset。其实使用右移运算符辅助判断也行，但是没有这个直观。