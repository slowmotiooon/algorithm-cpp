#pragma once

#include <vector>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
    vector<int> x, y;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] + (matrix[i][j] & 1) - sum[i][j];
            if (matrix[i][j] & 1) {
                x.push_back(i + 1);
                y.push_back(j + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < x.size(); i++) {
        int l = 0, r = min(m - x[i], n - y[i]);
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = sum[x[i] + mid][y[i] + mid] - sum[x[i] + mid][y[i] - 1] -
                      sum[x[i] - 1][y[i] + mid] + sum[x[i] - 1][y[i] - 1];
            if (val != (mid + 1) * (mid + 1))
                r = mid - 1;
            else
                l = mid + 1;
        }
        ans = max(ans, r * r + 2 * r + 1);
    }
    return ans;
}

// 通过 | 75ms | 40.38MB
// O(m*n*log(min(m,n))) | O(m*n)
// 二分，看起来还不是很快