#pragma once

#include <algorithm>
#include <vector>
using namespace std;

int countSquares(vector<vector<int>>& matrix) {
    int ans = 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j]) {
                dp[i + 1][j + 1] = min({ dp[i][j + 1], dp[i + 1][j], dp[i][j] }) + 1;
                ans += dp[i + 1][j + 1];
            }
            else
                dp[i + 1][j + 1] = 0;
        }
    }
    return ans;
}

// 通过 | 6ms | 28.48MB
// O(m*n) | O(m*n)
// 还得是动态规划。跟221题一样。