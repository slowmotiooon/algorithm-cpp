#pragma once

#include <functional>
#include <numeric>
#include <vector>
using namespace std;

int minOperations(vector<int>& nums, int k) {
    int xorSum = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    return __builtin_popcount(xorSum ^ k);
}

// 通过 | 122ms | 89.85MB
// O(n) | O(1)