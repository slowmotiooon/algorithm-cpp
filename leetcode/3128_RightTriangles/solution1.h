#pragma once

#include <vector>
using namespace std;

long long numberOfRightTriangles(vector<vector<int>>& grid) {
    long long ans = 0;
    int m = grid.size();
    int n = grid[0].size();

    vector<int> row(m), col(n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            row[i] += grid[i][j];
            col[j] += grid[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) ans += (row[i] - 1) * (col[j] - 1);
        }
    }
    return ans;
}

// 通过 | 21ms | 111.13MB
// O(n^m) | O(n+m)
// 还可以根据题解:
// https://leetcode.cn/problems/right-triangles/solutions/2758892/cheng-fa-yuan-li-pythonjavacgo-by-endles-7469
// 将空间复杂度降至O(n)