#pragma once

#include <vector>
using namespace std;

vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int n = nums.size();
    vector<int> sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + nums[i];
    }
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        ans[i] += (sum[n] - sum[i + 1]) - (n - 1 - i) * nums[i];
        ans[i] += i * nums[i] - (sum[i] - sum[0]);
    }
    return ans;
}

// 通过 | 7ms | 86.09MB
// O(n) | O(n)