#pragma once

#include <vector>
using namespace std;

void rotate(vector<int>& nums, int k) {
    if (k > nums.size()) k = k % nums.size();
    vector<int> result;
    for (int i = nums.size() - k; i < nums.size(); i++) {
        result.push_back(nums[i]);
    }

    for (int i = 0; i < nums.size() - k; i++) {
        result.push_back(nums[i]);
    }
    nums = result;
}

// 运行结果：
// 通过 | 23ms | 28.31MB
// O(n) | O(n)

// 方法1