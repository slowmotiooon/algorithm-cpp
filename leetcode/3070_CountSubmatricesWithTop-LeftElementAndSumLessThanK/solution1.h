#pragma once

#include <vector>
using namespace std;

int countSubmatrices(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size();
    int counter = 0;
    vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] + grid[i][j] - sum[i][j];
            if (sum[i + 1][j + 1] <= k) counter++;
        }
    }
    return counter;
}

// 通过 | 19ms | 97.99MB
// O(m*n) | O(m*n)