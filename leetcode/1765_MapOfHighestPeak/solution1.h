#pragma once

#include <queue>
#include <tuple>
#include <vector>
using namespace std;

vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int m = isWater.size();
    int n = isWater[0].size();
    vector<vector<int>> ans(m, vector<int>(n, 0));
    queue<tuple<int, int, int>> q;
    int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isWater[i][j]) q.push({ i, j, 0 });
        }
    }

    while (!q.empty()) {
        int i = get<0>(q.front());
        int j = get<1>(q.front());
        int h = get<2>(q.front());
        for (int a = 0; a < 4; a++) {
            if (i + dir[a][0] >= 0 && i + dir[a][0] < m && j + dir[a][1] >= 0 &&
                j + dir[a][1] < n && !isWater[i + dir[a][0]][j + dir[a][1]]) {
                isWater[i + dir[a][0]][j + dir[a][1]] = 1;
                ans[i + dir[a][0]][j + dir[a][1]] = h + 1;
                q.push({ i + dir[a][0], j + dir[a][1], h + 1 });
            }
        }
        q.pop();
    }
    return ans;
}

// 通过 | 261ms | 116.28MB
// O(m*n) | O(m*n)
//