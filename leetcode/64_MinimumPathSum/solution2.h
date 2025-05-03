#pragma once

#include <vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> dp(n + 1, INT_MAX);
    dp[1] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) { dp[j + 1] = min(dp[j + 1], dp[j]) + grid[i][j]; }
    }
    return dp[n];
}

// 通过 | 0ms | 15.18MB
// O(m*n) | O(n)
// 空间优化后的二维dp
