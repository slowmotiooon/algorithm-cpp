#pragma once

#include <vector>
using namespace std;

class NumMatrix
{
    vector<vector<int>> sumMatrix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        sumMatrix = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sumMatrix[i + 1][j + 1] =
                    sumMatrix[i + 1][j] + sumMatrix[i][j + 1] + matrix[i][j] - sumMatrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sumMatrix[row2 + 1][col2 + 1] - sumMatrix[row2 + 1][col1] -
               sumMatrix[row1][col2 + 1] + sumMatrix[row1][col1];
    }
};

// 通过 | 19ms | 144.06MB
// O(mn) | O(mn)