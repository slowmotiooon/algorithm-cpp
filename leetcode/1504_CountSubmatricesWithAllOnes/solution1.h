#pragma once

#include <climits>
#include <vector>
using namespace std;

int numSubmat(vector<vector<int>>& mat) {
    int ans = 0;
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> dp(m, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j])
                dp[i][j + 1] = dp[i][j] + 1;
            else
                dp[i][j + 1] = 0;
            int minVal = INT_MAX;
            for (int k = i; k >= 0; k--) {
                minVal = min(dp[k][j + 1], minVal);
                ans += minVal;
            }
        }
    }
    return ans;
}

// 通过 | 17.84MB
// O(n^2*m) | O(m*n)
// 思路来自：
// https://leetcode.cn/problems/count-submatrices-with-all-ones/solutions/317198/cdong-tai-gui-hua-by-keshawn_lu