#pragma once

#include <vector>
using namespace std;

static int ans = 0;

inline void dfs(vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1) return;

    if (i == 0 || (grid[i - 1][j] != 1 && grid[i - 1][j] != -1)) ans++;
    if (i == grid.size() - 1 || (grid[i + 1][j] != 1 && grid[i + 1][j] != -1)) ans++;
    if (j == 0 || (grid[i][j - 1] != 1 && grid[i][j - 1] != -1)) ans++;
    if (j == grid[0].size() - 1 || (grid[i][j + 1] != 1 && grid[i][j + 1] != -1)) ans++;

    grid[i][j] = -1;

    dfs(grid, i - 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i + 1, j);
    dfs(grid, i, j + 1);
}

inline int islandPerimeter(vector<vector<int>>& grid) {
    for (int i = 0; i < grid.size(); i++) {
        if (ans != 0) break;
        for (int j = 0; j < grid[0].size(); j++) {
            if (ans != 0) break;
            if (grid[i][j] == 1) dfs(grid, i, j);
        }
    }
    return ans;
}

// 通过 | 99ms | 100.68MB
// O(m*n) | O(m*n)
// 注意dfs中相邻地块是否为陆地的判别条件
