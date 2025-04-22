#pragma once

#include <numeric>
#include <vector>
using namespace std;

vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int pre = 0, suf = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        suf -= nums[i];
        ans[i] += suf - (n - i - 1) * nums[i];
        ans[i] += i * nums[i] - pre;
        pre += nums[i];
    }
    return ans;
}

// 通过 | 11ms | 83.92MB
// O(n) | O(1)
// 思路来自：https://leetcode.cn/problems/sum-of-absolute-differences-in-a-sorted-array/solutions/2811642/qian-zhui-he-by-yi-cheng-8i-5yc5
