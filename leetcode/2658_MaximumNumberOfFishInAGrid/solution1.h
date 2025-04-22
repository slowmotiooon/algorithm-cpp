#pragma once

#include <vector>
using namespace std;

void dfs(vector<vector<int>>& grid, int i, int j, int& current) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] <= 0) return;

    current += grid[i][j];
    grid[i][j] = -1;

    dfs(grid, i - 1, j, current);
    dfs(grid, i, j - 1, current);
    dfs(grid, i + 1, j, current);
    dfs(grid, i, j + 1, current);
}

int findMaxFish(vector<vector<int>>& grid) {
    int ans = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            int current = 0;
            if (grid[i][j] != 0) {
                dfs(grid, i, j, current);
                if (current > ans) ans = current;
            }
        }
    }
    return ans;
}

// 通过 | 40ms | 92.39MB
// O(m*n) | O(m*n)