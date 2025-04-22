#pragma once

#include <functional>
#include <numeric>
#include <vector>
using namespace std;

int xorBeauty(vector<int>& nums) {
    return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
}

// 通过 | 65ms | 41.46MB
// O(n) | O(1)
// 证明方法可以查看
// https://leetcode.cn/problems/find-xor-beauty-of-array/solutions/2050235/chai-wei-hua-jian-cheng-yi-ge-piao-liang-pun6