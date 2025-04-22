#pragma once

#include <algorithm>
#include <vector>
using namespace std;

int longestSubarray(vector<int>& nums) {
    int ans = 0;
    int maxAns = 0;
    int maxNum = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > maxNum) {
            ans = 1;
            maxAns = 0;
            maxNum = nums[i];
        }
        else if (nums[i] == maxNum)
            ans++;
        else {
            if (ans > maxAns) maxAns = ans;
            ans = 0;
        }
    }
    return maxAns > ans ? maxAns : ans;
}

// 通过 | 107ms | 83MB
// O(n) | O(1)

// 两次遍历的写法：

int longestSubarray1(vector<int>& nums) {
    int maxNum = *max_element(nums.begin(), nums.end());
    int ans = 0, count = 0;
    for (int x : nums) {
        if (x == maxNum) {
            count++;
            ans = ans < count ? count : ans;
        }
        else
            count = 0;
    }
    return ans;
}

// 通过 | 123ms | 82.93MB