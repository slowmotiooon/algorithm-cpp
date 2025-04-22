#pragma once

#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int kthLargestValue(vector<vector<int>>& matrix, int k) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> xorSum(m + 1, vector<int>(n + 1, 0));
    vector<int> nums;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            xorSum[i + 1][j + 1] =
                xorSum[i][j + 1] ^ xorSum[i + 1][j] ^ matrix[i][j] ^ xorSum[i][j];
            nums.push_back(xorSum[i + 1][j + 1]);
        }
    }
    sort(nums.begin(), nums.end(), greater<int>());
    return nums[k - 1];
}

// 通过 | 149ms | 127.13MB
// O(m*n(1+log(m*n))) | O(m*n)