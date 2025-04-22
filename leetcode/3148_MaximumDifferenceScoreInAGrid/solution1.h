#pragma once

#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int maxScore(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int ans = INT_MIN;
    vector<vector<int>> minh(m + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            minh[i + 1][j + 1] = min(minh[i][j + 1], minh[i + 1][j]);
            ans = max(ans, grid[i][j] - minh[i + 1][j + 1]);
            minh[i + 1][j + 1] = min(minh[i + 1][j + 1], grid[i][j]);
        }
    }
    return ans;
}

// 通过 | 16ms | 61.74MB
// O(m*n) | O(m*n)
// 思路来自：
// https://leetcode.cn/problems/maximum-difference-score-in-a-grid/solutions/2774823/nao-jin-ji-zhuan-wan-dppythonjavacgo-by-swux7