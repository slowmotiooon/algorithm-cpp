#pragma once

#include <vector>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> sums(n + 1, 0), counter(k, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        sums[i + 1] = sums[i] + nums[i];
    }
    for (int x : sums) {
        int mod = (x % k + k) % k;
        ans += counter[mod]++;
    }
    return ans;
}

// 通过 | 0ms | 33.13MB
// O(n) | O(n)
// 前缀和，注意C++中负数取模后可能为负数，所以需要将取模正数化。