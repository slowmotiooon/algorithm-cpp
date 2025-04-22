#pragma once

#include <vector>
using namespace std;

void dfs(vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || !grid[i][j]) return;

    grid[i][j] = 0;

    dfs(grid, i - 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i + 1, j);
    dfs(grid, i, j + 1);
}

int numEnclaves(vector<vector<int>>& grid) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (i != 0 && j != 0 && i != grid.size() - 1 && j != grid[0].size() - 1) continue;
            if (grid[i][j]) dfs(grid, i, j);
        }
    }
    int ans = 0;
    for (int i = 1; i < grid.size() - 1; i++) {
        for (int j = 1; j < grid[0].size() - 1; j++) {
            ans += grid[i][j];
        }
    }
    return ans;
}

// 通过 | 54ms | 32.26MB
// O(m*n) | O(m*n)
