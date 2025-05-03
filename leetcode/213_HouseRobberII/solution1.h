#pragma once

#include <vector>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> f(n + 2, 0);
    vector<int> g(n + 2, 0);
    f[0] = 0, f[1] = 0, g[0] = 0, g[1] = 0;
    for (int i = 0; i < n; i++) {
        if (i == n - 1)
            f[i + 2] = max(nums[i] + g[i], f[i + 1]);
        else
            f[i + 2] = max(nums[i] + f[i], f[i + 1]);
        if (i == 0)
            g[i + 2] = 0;
        else if (i == 1)
            g[i + 2] = nums[i];
        else if (i == 2)
            g[i + 2] = g[i + 1];
        else
            g[i + 2] = max(nums[i] + g[i], g[i + 1]);
    }
    return f[n + 1];
}