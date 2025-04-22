#pragma once

#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

long long maximumSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> sum(n + 1, 0);
    long long ans = -100000000000000;
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + nums[i];
        if (map.find(nums[i] + k) != map.end()) {
            ans = max(ans, sum[i + 1] - sum[map[nums[i] + k]]);
        }
        if (map.find(nums[i] - k) != map.end()) {
            ans = max(ans, sum[i + 1] - sum[map[nums[i] - k]]);
        }
        if (map.find(nums[i]) == map.end())
            map[nums[i]] = i;
        else if (sum[map[nums[i]]] > sum[i])
            map[nums[i]] = i;
    }
    return ans == -100000000000000 ? 0 : ans;
}

// 通过 | 218ms | 138.49MB
// O(n) | O(n)
// 思路来自：https://leetcode.cn/problems/maximum-good-subarray-sum/solutions/2630644/qian-zhui-he-ha-xi-biao-fu-ti-dan-python-z61d
