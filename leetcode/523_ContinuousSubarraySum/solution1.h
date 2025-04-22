#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    if (n < 2) return false;
    vector<int> sums(n + 1, 0);
    for (int i = 0; i < n; i++) sums[i + 1] = sums[i] + nums[i];
    unordered_map<int, int> counter;
    for (int i = 0; i <= n; i++) {
        int mod = sums[i] % k;
        if (counter.find(mod) != counter.end()) {
            if (counter[mod] + 1 != i) return true;
        }
        else
            counter[mod] = i;
    }
    return false;
}

// 通过 | 111ms | 147.97MB
// O(n) | O(n)