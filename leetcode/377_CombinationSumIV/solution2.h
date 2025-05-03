#pragma once

#include <vector>
using namespace std;

int combinationSum4(vector<int>& nums, int target) {
    vector<unsigned long long> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 0; i <= target; i++) {
        for (int x : nums) {
            if (i >= x) dp[i] += dp[i - x];
        }
    }

    return dp[target];
}

// 通过 | 0ms | 9.25MB
// O(n*target) | O(target)