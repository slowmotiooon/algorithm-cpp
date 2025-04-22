#pragma once

#include <algorithm>
#include <vector>
using namespace std;

int dfs(vector<vector<int>>& grid, int i, int j, int& current, int pre) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] <= pre) return 0;

    int max1   = dfs(grid, i - 1, j + 1, current, grid[i][j]);
    int max2   = dfs(grid, i, j + 1, current, grid[i][j]);
    int max3   = dfs(grid, i + 1, j + 1, current, grid[i][j]);
    grid[i][j] = 0;
    return max({ max1, max2, max3 }) + (pre != 0);
}

int maxMoves(vector<vector<int>>& grid) {
    int ans = 0;
    for (int i = 0; i < grid.size(); i++) {
        if (ans == grid[0].size() - 1) return ans;
        int current = dfs(grid, i, 0, current, 0);
        if (ans < current) ans = current;
    }
    return ans;
}

// 通过 | 156ms | 65.65MB
// O(m*n) | O(n)
// 1. 注意行列的区别        2. 在遍历后需要把已遍历的格子做标记（13行），防止超时。