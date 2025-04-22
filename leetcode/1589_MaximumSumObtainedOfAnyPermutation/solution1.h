#pragma once

#include <algorithm>
#include <vector>
using namespace std;

int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
    int n = nums.size();
    vector<int> diff(n + 1, 0);
    for (auto& x : requests) {
        diff[x[0]]++;
        diff[x[1] + 1]--;
    }
    int counter = 0;
    vector<int> sums(n, 0);
    for (int i = 0; i < n; i++) {
        counter += diff[i];
        sums[i] = counter;
    }
    sort(sums.begin(), sums.end());
    sort(nums.begin(), nums.end());
    long ans = 0;
    for (int i = 0; i < n; i++) {
        if (!sums[i]) continue;
        ans += (long)sums[i] * nums[i];
        ans %= 1000000007;
    }
    return ans;
}

// 通过 | 43ms | 96.67MB
// O(n*log(n)) | O(n)