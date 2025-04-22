#pragma once

#include <vector>
using namespace std;

vector<vector<int>> p, a, ans;

int n, m;

void dfs(vector<vector<int>>& heights, vector<vector<int>>& v, int i, int j) {
    if (v[i][j]) return;
    v[i][j] = 1;

    if (p[i][j] && a[i][j]) ans.push_back({ i, j });

    if (i - 1 >= 0 && heights[i - 1][j] >= heights[i][j]) dfs(heights, v, i - 1, j);
    if (i + 1 < n && heights[i + 1][j] >= heights[i][j]) dfs(heights, v, i + 1, j);
    if (j - 1 >= 0 && heights[i][j - 1] >= heights[i][j]) dfs(heights, v, i, j - 1);
    if (j + 1 < m && heights[i][j + 1] >= heights[i][j]) dfs(heights, v, i, j + 1);
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    n = heights.size();
    m = heights[0].size();
    p = vector<vector<int>>(n, vector<int>(m, 0));
    a = vector<vector<int>>(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        dfs(heights, p, i, 0);
        dfs(heights, a, i, m - 1);
    }
    for (int j = 0; j < m; j++) {
        dfs(heights, p, 0, j);
        dfs(heights, a, n - 1, j);
    }
    return ans;
}

// 通过 | 28ms | 26.19MB
// O(m*n) | O(m*n)
// 题解来自：https://leetcode.cn/problems/pacific-atlantic-water-flow/solutions/754024/shui-wang-gao-chu-liu-by-xiaohu9527-xxsx