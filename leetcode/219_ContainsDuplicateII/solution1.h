#pragma once

#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> counter;
    for (int i = 0; i < nums.size(); i++) {
        counter[nums[i]]++;
        if (counter[nums[i]] > 1) return true;
        if (i < k) continue;
        counter[nums[i - k]]--;
    }
    return false;
}

// 通过 | 155ms | 79.29MB
// O(n) | O(k)
// 类定长滑窗
// 使用unordered_set优化版

bool betterContainsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> counter;
    for (int i = 0; i < nums.size(); i++) {
        if (counter.count(nums[i])) return true;
        counter.insert(nums[i]);
        if (i < k) continue;
        counter.erase(nums[i - k]);
    }
    return false;
}

// 通过 | 123ms | 74.60MB
// O(n) | O(k)