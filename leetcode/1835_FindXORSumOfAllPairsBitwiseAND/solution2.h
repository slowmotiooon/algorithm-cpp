#pragma once

#include <functional>
#include <numeric>
#include <vector>
using namespace std;

int getXORSum(vector<int>& arr1, vector<int>& arr2) {
    int a = accumulate(arr1.begin(), arr1.end(), 0, bit_xor<int>());
    int b = accumulate(arr2.begin(), arr2.end(), 0, bit_xor<int>());
    return a & b;
}

// 通过 | 100ms | 93.87MB
// O(n+m) | O(1)
// 根据解法一的思路优化。
// 甚至还能压缩一下

int getXORSum2(vector<int>& arr1, vector<int>& arr2) {
    return accumulate(arr1.begin(), arr1.end(), 0, bit_xor<int>()) &
           accumulate(arr2.begin(), arr2.end(), 0, bit_xor<int>());
}