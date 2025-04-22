#pragma once

#include <bits/stl_algobase.h>
using namespace std;

int findComplement(int num) {
    int m = 31 - __lg(num);
    return (~(num << m)) >> m;
}

// 通过 | 3ms | 7.30MB
// O(1) | O(1)
// 直接取反会变负数，所以需要把最高有效位移动到最高位，取反后再移动回原位。