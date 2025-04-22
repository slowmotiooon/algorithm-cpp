#pragma once

#include <functional>
#include <numeric>
#include <vector>
using namespace std;

bool doesValidArrayExist(vector<int>& derived) {
    return accumulate(derived.begin(), derived.end(), 0, bit_xor<int>()) == 0;
}

// 通过 | 211ms | 256.95MB
// O(n) | O(1)
// 思路来源：https://leetcode.cn/problems/neighboring-bitwise-xor/solutions/2269241/tui-gong-shi-by-endlesscheng-90t5
// 还有注意的一点是各种函数的用法及所需要的库