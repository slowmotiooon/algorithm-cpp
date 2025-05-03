#pragma once

#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        vector<int> f(n, 0), f1(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0)
                    f[j] = grid[i][j];
                else {
                    int minVal = INT_MAX;
                    for (int k = 0; k < n; k++) {
                        f1[k] += moveCost[grid[i - 1][k]][j];
                        minVal = min(minVal, f1[k]);
                    }
                    f[j] = minVal + grid[i][j];
                }
            }
            f1 = f;
        }
        return *min_element(f.begin(), f.end());
    }
};
