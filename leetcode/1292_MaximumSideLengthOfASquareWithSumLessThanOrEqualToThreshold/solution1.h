#pragma once

#include <vector>
using namespace std;

int maxSideLength(vector<vector<int>>& mat, int threshold) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] + mat[i][j] - sum[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int l = 0, r = min(m - i, n - j);
            int mid = 0;
            while (l <= r) {
                mid = l + (r - l) / 2;
                int s = sum[i + mid][j + mid] - sum[i + mid][j - 1] - sum[i - 1][j + mid] +
                        sum[i - 1][j - 1];
                if (s > threshold)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            ans = max(ans, l);
        }
    }
    return ans;
}

// 通过 | 23ms | 30.75MB
// O(m*n*log(min(m,n))) | O(m*n)
// 寻找符合条件的最大正方形边长可以用二分查找