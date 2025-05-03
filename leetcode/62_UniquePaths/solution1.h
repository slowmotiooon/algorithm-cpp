#pragma once

#include <vector>
using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < m; i++) {
            if (i) dp[0] = 0;
            for (int j = 0; j < n; j++) dp[j + 1] += dp[j];
        }
        return dp[n];
    }
};

// 通过 | 0ms | 8.11MB
// O(m*n) | O(n)
// 本质和64题相同，只不过64题可以通过原地修改grid[0]来实现O(1)的空间优化，这个只能优化到O(n).
