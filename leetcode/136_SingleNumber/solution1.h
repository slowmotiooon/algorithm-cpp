#pragma once

#include <functional>
#include <numeric>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
}

// 通过 | 17ms | 19.07MB
// O(n) | O(1)
