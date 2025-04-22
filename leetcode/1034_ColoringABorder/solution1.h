#pragma once

#include <unordered_set>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& grid, int i, int j, int target) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] < 1 ||
        grid[i][j] != target)
        return;

    if (i == 0 || (grid[i - 1][j] != target && grid[i - 1][j] >= 1))
        grid[i][j] = -1;
    else if (j == 0 || (grid[i][j - 1] != target && grid[i][j - 1] >= 1))
        grid[i][j] = -1;
    else if (i == grid.size() - 1 || (grid[i + 1][j] != target && grid[i + 1][j] >= 1))
        grid[i][j] = -1;
    else if (j == grid[0].size() - 1 || (grid[i][j + 1] != target && grid[i][j + 1] >= 1))
        grid[i][j] = -1;
    else
        grid[i][j] = 0;

    dfs(grid, i - 1, j, target);
    dfs(grid, i, j - 1, target);
    dfs(grid, i + 1, j, target);
    dfs(grid, i, j + 1, target);
}

vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
    int target = grid[row][col];
    dfs(grid, row, col, grid[row][col]);
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 0) grid[i][j] = target;
            if (grid[i][j] == -1) grid[i][j] = color;
        }
    }
    return grid;
}

// 通过 | 12ms | 15.82MB
// O(m*n) | O(1)