#pragma once

#include <vector>
using namespace std;

void dfs(vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j]) return;

    grid[i][j] = 1;

    dfs(grid, i - 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i + 1, j);
    dfs(grid, i, j + 1);
}

int closedIsland(vector<vector<int>>& grid) {
    if (grid.size() < 3 || grid[0].size() < 3) return 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (i != 0 && j != 0 && i != grid.size() - 1 && j != grid[0].size() - 1) continue;
            if (!grid[i][j]) dfs(grid, i, j);
        }
    }
    int ans = 0;
    for (int i = 1; i < grid.size() - 1; i++) {
        for (int j = 1; j < grid[0].size() - 1; j++) {
            if (!grid[i][j]) {
                ans++;
                dfs(grid, i, j);
            }
        }
    }
    return ans;
}

// 通过 | 11ms | 11.93MB
// O(m*n) | O(m*n)
// 思路来源：https://leetcode.cn/problems/number-of-closed-islands/solutions/2312616/liang-chong-si-lu-xian-wai-hou-nei-chu-j-b1e4
// 方法一