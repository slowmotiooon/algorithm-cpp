#pragma once

#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

long long maximumTripletValue(vector<int>& nums) {
    int n = nums.size();
    vector<int> sufMax(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        sufMax[i] = max(sufMax[i + 1], nums[i]);
    }
    long long ans = 0;
    int preMax = nums[0];
    for (int i = 0; i < n - 1; i++) {
        ans = max(ans, (long long)(preMax - nums[i]) * sufMax[i + 1]);
        preMax = max(nums[i], preMax);
    }
    return ans;
}

// 通过 | 126ms | 91.43MB
// O(n) | O(n)
// 题解来自：https://leetcode.cn/problems/maximum-value-of-an-ordered-triplet-ii/solutions/2464857/mei-ju-jzhao-qian-hou-zui-da-zhi-pythonj-um8q