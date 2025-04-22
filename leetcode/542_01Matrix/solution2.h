#pragma once

#include <queue>
#include <tuple>
#include <vector>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    queue<tuple<int, int, int>> q;
    int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    vector<vector<int>> ans(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!mat[i][j]) {
                bool checked = false;
                if (i != 0 && mat[i - 1][j]) checked = true;
                if (i != m - 1 && mat[i + 1][j] && !checked) checked = true;
                if (j != 0 && mat[i][j - 1] && !checked) checked = true;
                if (j != n - 1 && mat[i][j + 1] && !checked) checked = true;
                if (checked) q.push({ i, j, 0 });
            }
        }
    }

    while (!q.empty()) {
        int i = get<0>(q.front());
        int j = get<1>(q.front());
        int step = get<2>(q.front());
        for (int a = 0; a < 4; a++) {
            if (i + dir[a][0] >= 0 && i + dir[a][0] < m && j + dir[a][1] >= 0 &&
                j + dir[a][1] < n && mat[i + dir[a][0]][j + dir[a][1]]) {
                ans[i + dir[a][0]][j + dir[a][1]] = step + 1;
                q.push({ i + dir[a][0], j + dir[a][1], step + 1 });
                mat[i + dir[a][0]][j + dir[a][1]] = 0;
            }
        }
        q.pop();
    }
    return ans;
}

// 通过 | 62ms | 34.46MB
// O(m*n) | O(m*n)
// 多源BFS，选取源时去除了多余的源（指上下左右没有1的0方格），但是效率不如方法1