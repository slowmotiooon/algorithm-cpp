#pragma once

#include <functional>
#include <numeric>
#include <vector>
using namespace std;

vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int n = nums.size();
    int xor_ = 0;
    int mask = 0xffffffff << maximumBit;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        xor_ ^= nums[i];
        ans[n - i - 1] = ~(xor_ ^ mask);
    }
    return ans;
}

// 通过 | 110ms | 93.22MB
// O(n) | O(1)
// 思路相同，一次循环版