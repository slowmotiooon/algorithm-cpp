#pragma once

#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int xor1_ = accumulate(nums1.begin(), nums1.end(), 0, bit_xor<int>());
    int xor2_ = accumulate(nums2.begin(), nums2.end(), 0, bit_xor<int>());

    int ans = 0;
    if (nums1.size() & 1) ans ^= xor2_;
    if (nums2.size() & 1) ans ^= xor1_;
    return ans;
}

// 通过 | 114ms | 61.75MB
// O(n+m) | O(1)