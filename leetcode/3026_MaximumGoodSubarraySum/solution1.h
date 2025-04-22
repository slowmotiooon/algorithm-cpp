#pragma once

#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

long long maximumSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> sum(n + 1, 0);
    long long ans = -100000000000000;
    unordered_map<int, vector<int>> map;
    for (int i = 0; i < n; i++) {
        sum[i + 1] = nums[i] + sum[i];
        if (map.find(nums[i] + k) != map.end()) {
            for (int x : map[nums[i] + k]) {
                ans = max(ans, sum[i + 1] - sum[x]);
            }
        }
        if (map.find(nums[i] - k) != map.end()) {
            for (int x : map[nums[i] - k]) {
                ans = max(ans, sum[i + 1] - sum[x]);
            }
        }

        map[nums[i]].push_back(i);
    }
    return ans == -100000000000000 ? 0 : ans;
}

// 超出时间限制
// 最坏O(n^2) | O(n)