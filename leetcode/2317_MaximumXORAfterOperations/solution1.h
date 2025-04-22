#pragma once

#include <functional>
#include <numeric>
#include <vector>
using namespace std;

int maximumXOR(vector<int>& nums) {
    return accumulate(nums.begin(), nums.end(), 0, bit_or<int>());
}

// 通过 | 76ms | 49.47MB
// O(n) | O(1)
// 异或和的结果由每一位的1数量决定，如果有奇数个1，那就是1，偶数个就是0.
// 要想增加最大异或和，就需要尽可能将所有的0变成1.
// 由于对一个数字nums[i]的处理只能得到小于等于nums[i]的数
// 因此，只能对含有大于零的偶数个1的位数可以变为1
// 此时最大异或和就是把所有的元素按位或。