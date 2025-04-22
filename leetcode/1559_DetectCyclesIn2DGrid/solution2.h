#pragma once

#include <vector>
using namespace std;

int m, n;
vector<vector<bool>> v;
bool ans = false;

void dfs(vector<vector<char>>& grid, int i, int j, int current, vector<int> prev = { -1, -1 }) {
    if (current != grid[i][j] && ans) return;
    if (v[i][j] == 1) {
        ans = true;
        v[prev[0]][prev[1]] = 2;
        return;
    }

    v[i][j] = true;
    vector<int> p = { i, j };

    if (i > 0 && prev[0] != i - 1 && !ans) dfs(grid, i - 1, j, current, p);
    if (i < m - 1 && prev[0] != i + 1 && !ans) dfs(grid, i + 1, j, current, p);
    if (j > 0 && prev[1] != j - 1 && !ans) dfs(grid, i, j - 1, current, p);
    if (j < n - 1 && prev[1] != j + 1 && !ans) dfs(grid, i, j + 1, current, p);
}

bool containsCycle(vector<vector<char>>& grid) {
    m = grid.size();
    n = grid[0].size();
    v = vector<vector<bool>>(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!v[i][j]) dfs(grid, i, j, grid[i][j]);
            if (ans) return ans;
        }
    }
    return ans;
}

// 通过 | 1772ms | 228.04MB
// O(m*n) | O(m*n)