#pragma once

#include <vector>
#include <algorithm>
using namespace std;

long long countSubarrays(vector<int>& nums, int k) {
    int mx = *max_element(nums.begin(),nums.end());
    long long ans = 0;
    int cnt_mx = 0, left = 0;
    for (int x : nums) {
        cnt_mx += x == mx;
        while (cnt_mx == k) {
            cnt_mx -= nums[left++] == mx;
        }
        ans += left;
    }
    return ans;
}

// 题解来自：https://leetcode.cn/problems/count-subarrays-where-max-element-appears-at-least-k-times/solutions/2560940/hua-dong-chuang-kou-fu-ti-dan-pythonjava-xvwg
// O(n) | O(1)
