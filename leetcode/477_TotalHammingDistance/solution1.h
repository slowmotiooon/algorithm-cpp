#pragma once

#include <vector>
using namespace std;

int totalHammingDistance(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            ans += __builtin_popcount(nums[i] ^ nums[j]);
        }
    }
    return ans;
}

// 通过 | 1359ms | 21.18MB
// O(n^2) | O(1)
// 暴力都能过？