#pragma once

#include <vector>
using namespace std;

int numberOfSubmatrices(vector<vector<char>>& grid) {
    int ans = 0;
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> xs(m + 1, vector<int>(n + 1, 0));
    vector<vector<int>> ys(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            xs[i + 1][j + 1] = xs[i][j + 1] + xs[i + 1][j] + (grid[i][j] == 'X') - xs[i][j];
            ys[i + 1][j + 1] = ys[i][j + 1] + ys[i + 1][j] + (grid[i][j] == 'Y') - ys[i][j];
            if (xs[i + 1][j + 1] == ys[i + 1][j + 1] && xs[i + 1][j + 1]) ans++;
        }
    }
    return ans;
}

// 通过 | 51ms | 127.32MB
// O(m*n) | O(m*n)