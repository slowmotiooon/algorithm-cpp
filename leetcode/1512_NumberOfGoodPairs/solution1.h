#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

int numIdenticalPairs(vector<int>& nums) {
    unordered_map<int, int> counter;
    for (int i = 0; i < nums.size(); i++) {
        counter[nums[i]]++;
    }
    int ans = 0;
    for (auto x : counter) {
        ans += (x.second * (x.second - 1) / 2);
    }
    return ans;
}

// 通过 | 4ms | 9.01MB
// O(n) | O(n)
// 一次遍历优化版算法：

int betterNumIdenticalPairs(vector<int>& nums) {
    unordered_map<int, int> counter;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        ans += counter[nums[i]];
        counter[nums[i]]++;
    }
    return ans;
}

// 通过 | 0ms | 9.15MB
// O(n) | O(1)