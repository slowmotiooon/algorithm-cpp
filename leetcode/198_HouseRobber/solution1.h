#pragma once

#include <vector>
using namespace std;

int dfs(vector<int>& nums, int p) {
    if (p == -1 || p == -2) return 0;
    return max(dfs(nums, p - 1), dfs(nums, p - 2) + nums[p]);
}

int rob(vector<int>& nums) {
    return dfs(nums, nums.size() - 1);
}

// 超出时间限制
// 原因是重复计算
// “但是这样的递归会有很多重复计算，比如对于p=3的情况，可能需要多次计算p=1和p=0的情况。这会导致时间复杂度非常高，类似于斐波那契数列的递归树结构，时间复杂度是O(2^n)，对于较大的n来说，这是不可行的。
// -- DeepSeek”