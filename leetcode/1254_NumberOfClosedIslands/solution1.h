#pragma once

#include <vector>
using namespace std;

bool dfs(vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j]) return true;

    bool checked = true;
    if (i == 0 || j == 0 || i == grid.size() - 1 || j == grid[0].size() - 1) checked = false;
    grid[i][j] = 2;

    if (!dfs(grid, i - 1, j)) checked = false;
    if (!dfs(grid, i, j - 1)) checked = false;
    if (!dfs(grid, i + 1, j)) checked = false;
    if (!dfs(grid, i, j + 1)) checked = false;

    return checked;
}

int closedIsland(vector<vector<int>>& grid) {
    int ans = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (!grid[i][j]) {
                if (dfs(grid, i, j)) ans++;
            }
        }
    }
    return ans;
}

// 通过 | 9ms | 11.92MB
// O(m*n) | O(m*n)