#pragma once

#include <vector>
using namespace std;

inline void dfs(vector<vector<int>>& grid, int i, int j, int& area)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 ||
        grid[i][j] == 2)
        return;

    grid[i][j] = 2;
    area++;
    dfs(grid, i + 1, j, area);
    dfs(grid, i, j + 1, area);
    dfs(grid, i - 1, j, area);
    dfs(grid, i, j - 1, area);
}

inline int maxAreaOfIsland(vector<vector<int>>& grid)
{
    int maxArea = 0;
    int area    = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) {
                area = 0;
                dfs(grid, i, j, area);
                if (maxArea < area) maxArea = area;
            }
        }
    }
    return maxArea;
}

// 通过 | 11ms | 26.41MB
// O(m*n) | O(m*n)  空间复杂度来源于dfs函数的栈开销。
// 网格图dfs样板题，跟200. 岛屿数量 (https://leetcode.cn/problems/number-of-islands/ 异曲同工。
