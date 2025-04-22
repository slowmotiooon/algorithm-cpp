#pragma once

#include <vector>
using namespace std;

vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (vector<int>& x : queries) {
        mat[x[0]][x[1]]++;
        if (x[2] != n - 1) mat[x[2] + 1][x[1]]--;
        if (x[3] != n - 1) mat[x[0]][x[3] + 1]--;
        if (x[2] != n - 1 && x[3] != n - 1) mat[x[2] + 1][x[3] + 1]++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != 0) mat[i][j] += mat[i - 1][j];
            if (j != 0) mat[i][j] += mat[i][j - 1];
            if (i != 0 && j != 0) mat[i][j] -= mat[i - 1][j - 1];
        }
    }
    return mat;
}

// 通过 | 24ms | 83.74MB | 11:19 | 0x
// O(n^2+k) | O(1)
// 二维差分。