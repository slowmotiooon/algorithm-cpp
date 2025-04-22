#pragma once

#include <string>
#include <vector>
using namespace std;

inline void dfs(vector<string>& grid, int i, int j, bool& checked, int& area, char current) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != current) return;

    if (i == 0 || grid[i - 1][j] == '0') checked = false;
    if (j == 0 || grid[i][j - 1] == '0') checked = false;
    if (i == grid.size() - 1 || grid[i + 1][j] == '0') checked = false;
    if (j == grid[0].size() - 1 || grid[i][j + 1] == '0') checked = false;

    // 处理
    area++;
    grid[i][j] = '\0';

    // 向上下左右四个方向遍历
    dfs(grid, i + 1, j, checked, area, current);
    dfs(grid, i, j + 1, checked, area, current);
    dfs(grid, i - 1, j, checked, area, current);
    dfs(grid, i, j - 1, checked, area, current);
}

inline int largestArea(vector<string>& grid) {
    int area = 0;
    int ans  = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] != '0' && grid[i][j] != '\0') {
                bool checked = true;
                area         = 0;
                dfs(grid, i, j, checked, area, grid[i][j]);
                if (checked) ans = ans < area ? area : ans;
            }
        }
    }
    return ans;
}

// 通过 | 161ms | 18.59MB
// O(m*n) | O(m*n)
