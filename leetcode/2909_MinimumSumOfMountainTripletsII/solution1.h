#pragma once

#include <climits>
#include <vector>
using namespace std;

int minimumSum(vector<int> nums) {
    int ans = INT_MAX;
    for (int i = 1; i < nums.size() - 1; i++) {
        int leftMin = INT_MAX, rightMin = INT_MAX;
        for (int left = i - 1; left >= 0; left--) {
            if (nums[left] < nums[i]) leftMin = min(leftMin, nums[left]);
        }
        if (leftMin == INT_MAX) continue;
        for (int right = i + 1; right < nums.size(); right++) {
            if (nums[right] < nums[i]) rightMin = min(rightMin, nums[right]);
        }
        if (rightMin == INT_MAX) continue;
        ans = min(ans, leftMin + nums[i] + rightMin);
    }
    return ans == INT_MAX ? -1 : ans;
}

// 超出时间限制
// O(n^2) | O(1)