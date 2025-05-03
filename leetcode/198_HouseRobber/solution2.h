#pragma once

#include <vector>
using namespace std;

vector<int> cache;

int dfs(vector<int>& nums, int p) {
    if (p < 0) return 0;
    if (cache[p] == -1) cache[p] = max(dfs(nums, p - 1), dfs(nums, p - 2) + nums[p]);
    return cache[p];
}

int rob(vector<int>& nums) {
    cache = vector<int>(nums.size(), -1);
    return dfs(nums, nums.size() - 1);
}

// 通过 | 0ms | 10.43MB
// O(n) | O(n)
// 用时间换空间。但是可以通过迭代法将空间优化至O(1)
// "由于每个状态只依赖于前两个状态，可以不用数组，只用变量来存储，从而将空间复杂度从O(n)降到O(1)。这一点对于用户理解优化过程很重要。
// --DeepSeek"