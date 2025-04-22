#pragma once

#include <vector>
using namespace std;

vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    vector<int> sum(n, 0);
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + ((nums[i] ^ nums[i - 1]) & 1);
    }
    vector<bool> ans;
    for (vector<int> x : queries) {
        ans.push_back(x[1] - x[0] == sum[x[1]] - sum[x[0]]);
    }
    return ans;
}

// 通过 | 50ms | 132.57MB
// O(n+k) | O(n)
// 前缀和