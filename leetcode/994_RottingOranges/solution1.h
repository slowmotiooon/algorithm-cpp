#pragma once

#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int counter = 0;
    int m = grid.size();
    int n = grid[0].size();
    queue<tuple<int, int, int>> q;
    int ans = 0;
    int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) q.push({ i, j, 0 });
            if (grid[i][j] == 1) counter++;
        }
    }
    if (!counter) return 0;

    while (!q.empty()) {
        int i = get<0>(q.front());
        int j = get<1>(q.front());
        int min = get<2>(q.front());

        for (int a = 0; a < 4; a++) {
            if (i + dir[a][0] >= 0 && i + dir[a][0] < m && j + dir[a][1] >= 0 &&
                j + dir[a][1] < n && grid[i + dir[a][0]][j + dir[a][1]] == 1) {
                grid[i + dir[a][0]][j + dir[a][1]] = 2;
                q.push({ i + dir[a][0], j + dir[a][1], min + 1 });
                ans = min + 1;
                counter--;
            }
        }

        q.pop();
    }

    return counter ? -1 : ans;
}

// 通过 | 4ms | 15.93MB
// O(m*n) | O(m*n)
// 多源BFS，通过counter获取变质结束后的剩余橘子数量。