#pragma once

#include <climits>
#include <vector>
using namespace std;

int minimumSum(vector<int> nums) {
    int n = nums.size();
    int ans = INT_MAX;
    vector<int> preMin(n + 1, INT_MAX), sufMin(n + 1, INT_MAX);
    for (int i = 0; i < n; i++) {
        preMin[i + 1] = min(preMin[i], nums[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        sufMin[i] = min(sufMin[i + 1], nums[i]);
    }
    for (int i = 1; i < n - 1; i++) {
        if (nums[i] > preMin[i] && nums[i] > sufMin[i + 1])
            ans = min(ans, nums[i] + preMin[i] + sufMin[i + 1]);
    }
    return ans == INT_MAX ? -1 : ans;
}

// 通过 | 18ms | 84.51MB
// O(n) | O(n)