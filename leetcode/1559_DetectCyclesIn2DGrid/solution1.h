#pragma once

#include <vector>
using namespace std;

int                 m, n;
int                 ans = 0;
vector<vector<int>> v;   // 0: not visited, 1: visited, 2: visited and makes the cycle

void dfs(vector<vector<char>>& grid, int i, int j, char current, vector<int> prev = { -1, -1 }) {
    if (current != grid[i][j]) return;
    if (v[i][j] == 1) {
        ans++;
        v[prev[0]][prev[1]] = 2;
        return;
    }

    v[i][j]       = 1;
    vector<int> p = { i, j };

    if (i > 0 && prev[0] != i - 1 && v[i - 1][j] != 2) dfs(grid, i - 1, j, current, p);
    if (i < m - 1 && prev[0] != i + 1 && v[i + 1][j] != 2) dfs(grid, i + 1, j, current, p);
    if (j > 0 && prev[1] != j - 1 && v[i][j - 1] != 2) dfs(grid, i, j - 1, current, p);
    if (j < n - 1 && prev[1] != j + 1 && v[i][j + 1] != 2) dfs(grid, i, j + 1, current, p);
}

bool containsCycle(vector<vector<char>>& grid) {
    m = grid.size();
    n = grid[0].size();
    v = vector<vector<int>>(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!v[i][j]) dfs(grid, i, j, grid[i][j]);
        }
    }
    return ans;
}

// 通过 | 2372ms | 411.30MB
// O(m*n) | O(m*n)
// dfs, 通过标记已访问(v[i][j]=1)和无法前进(v[i][j]=2)防止回溯或重复访问。
// md，题目只需要返回是否存在环就行，不需要计数。