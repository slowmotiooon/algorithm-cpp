#pragma once

#include <algorithm>
#include <vector>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int ans = 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1')
                dp[i + 1][j + 1] = min({ dp[i][j + 1], dp[i][j], dp[i + 1][j] }) + 1;
            else
                dp[i + 1][j + 1] = 0;
            ans = max(ans, dp[i + 1][j + 1]);
        }
    }
    return ans * ans;
}

// 通过 | 7ms | 29.74MB
// O(m*n) | O(m*n)
// 还得是动态规划。