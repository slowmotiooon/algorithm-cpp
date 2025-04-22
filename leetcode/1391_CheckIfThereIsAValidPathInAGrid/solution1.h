#pragma once

#include <vector>
using namespace std;


// dir: 0:init, 1:up, 2:down, 3:left, 4:right
bool dfs(vector<vector<int>> grid, int i, int j, int dir) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) return false;

    if (grid[i][j] == 1 && (dir == 1 || dir == 2)) return false;
    if (grid[i][j] == 2 && (dir == 3 || dir == 4)) return false;
    if (grid[i][j] == 3 && (dir == 2 || dir == 3)) return false;
    if (grid[i][j] == 4 && (dir == 2 || dir == 4)) return false;
    if (grid[i][j] == 5 && (dir == 1 || dir == 3)) return false;
    if (grid[i][j] == 6 && (dir == 1 || dir == 4)) return false;

    if (i == grid.size() - 1 && j == grid[0].size() - 1) return true;

    int current  = grid[i][j];
    grid[i][j]   = 0;
    bool checked = false;

    if ((current == 2 || current == 5 || current == 6) && dfs(grid, i - 1, j, 1)) checked = true;

    if ((current == 2 || current == 3 || current == 4) && dfs(grid, i + 1, j, 2)) checked = true;

    if ((current == 1 || current == 3 || current == 5) && dfs(grid, i, j - 1, 3)) checked = true;

    if ((current == 1 || current == 4 || current == 6) && dfs(grid, i, j + 1, 4)) checked = true;

    return checked;
}

bool hasValidPath(vector<vector<int>>& grid) {
    if (grid[0][0] == 5) return false;
    return dfs(grid, 0, 0, 0);
}

// 超出内存限制
// 大概率是爆栈了，算法本身应该没有什么问题。