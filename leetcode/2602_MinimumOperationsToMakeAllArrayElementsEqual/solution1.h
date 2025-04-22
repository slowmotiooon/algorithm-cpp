#pragma once

#include <algorithm>
#include <vector>
using namespace std;

vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<long long> sums(n + 1, 0);
    for (int i = 0; i < n; i++) {
        sums[i + 1] = nums[i] + sums[i];
    }
    vector<long long> ans;
    for (int q : queries) {
        int b = lower_bound(nums.begin(), nums.end(), q) - nums.begin();
        long long val = (sums[n] - sums[b]) - (long long)q * (n - b);
        val += (long long)b * q - (sums[b] - sums[0]);
        ans.push_back(val);
    }
    return ans;
}

// 通过 | 51ms | 83.88MB
// O((n+q)*log(n)) | O(n)
// 在看到题解上出现“二分”字样的时候我就知道怎么做了。
// 不得不说调库还是香。