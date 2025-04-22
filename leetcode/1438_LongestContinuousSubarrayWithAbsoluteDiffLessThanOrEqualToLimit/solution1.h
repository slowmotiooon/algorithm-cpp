#pragma once

#include <vector>
using namespace std;

int longestSubarray(vector<int>& nums, int limit) {
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        int maxval = nums[i];
        int minval = nums[i];
        for (int j = i; j < nums.size(); j++) {
            maxval = max(maxval, nums[j]);
            minval = min(minval, nums[j]);
            if (maxval - minval <= limit)
                ans = max(ans, j - i + 1);
            else
                break;
        }
    }
    return ans;
}

// 超出时间限制
