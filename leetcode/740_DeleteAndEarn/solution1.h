#pragma once

#include <algorithm>
#include <vector>
using namespace std;

int deleteAndEarn(vector<int>& nums) {
    int n = *max_element(nums.begin(), nums.end()) + 1;
    vector<int> cost(n);
    for (int x : nums) cost[x] += x;
    int f, f1 = 0, f2 = 0;
    for (int i = 0; i < n; i++) {
        f = max(cost[i] + f2, f1);
        f2 = f1;
        f1 = f;
    }
    return f;
}

// 通过 | 0ms | 15.34MB
// O(n+m) | O(m) m指nums中的最大值
// 整个算法的关键点在于前三行，前三行可以将该问题转化为打家劫舍问题。