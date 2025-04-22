#pragma once

#include <vector>
using namespace std;

vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] + mat[i][j] - sum[i][j];
        }
    }

    vector<vector<int>> ans(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        int maxr = min(i + 1 + k, m);
        int minr = max(i + 1 - k, 1);
        for (int j = 0; j < n; j++) {
            int maxc = min(j + 1 + k, n);
            int minc = max(j + 1 - k, 1);
            ans[i][j] = sum[maxr][maxc] - sum[maxr][minc - 1] - sum[minr - 1][maxc] +
                        sum[minr - 1][minc - 1];
        }
    }

    return ans;
}

// 通过 | 3ms | 11.86MB
// O(m*n) | O(m*n)