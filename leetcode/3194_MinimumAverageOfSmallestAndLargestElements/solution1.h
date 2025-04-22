#pragma once

#include <algorithm>
#include <vector>
using namespace std;

double minimumAverage(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    double ans = __DBL_MAX__;
    for (int i = 0; i < n / 2; i++) {
        ans = max(ans, (nums[i] + nums[n - 1 - i]) / (double)2);
    }

    return ans;
}

// 通过 | 7ms | 24.72MB
// O(n*log(n)) | O(1)
// 暴力O(n^2)应该也能过,毕竟难度就1200