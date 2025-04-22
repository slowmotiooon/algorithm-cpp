#pragma once

#include <vector>
using namespace std;

bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
    if (i < 0 || j < 0 || i >= grid2.size() || j >= grid2[0].size() || !grid2[i][j]) return true;

    bool checked = true;
    if (grid2[i][j] != grid1[i][j]) checked = false;
    grid2[i][j] = 0;

    if (!dfs(grid1, grid2, i - 1, j)) checked = false;
    if (!dfs(grid1, grid2, i, j - 1)) checked = false;
    if (!dfs(grid1, grid2, i + 1, j)) checked = false;
    if (!dfs(grid1, grid2, i, j + 1)) checked = false;

    return checked;
}

int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int ans = 0;
    for (int i = 0; i < grid2.size(); i++) {
        for (int j = 0; j < grid2[0].size(); j++) {
            if (grid2[i][j] && grid2[i][j] == grid1[i][j]) {
                if (dfs(grid1, grid2, i, j)) ans++;
            }
        }
    }
    return ans;
}

// 通过 | 219ms |89.78MB
// O(m*n) | O(m*n)