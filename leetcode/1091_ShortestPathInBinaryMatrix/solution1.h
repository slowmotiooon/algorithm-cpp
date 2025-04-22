#pragma once

#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    int dir[8][2] = { { -1, 0 }, { -1, 1 }, { 0, 1 },  { 1, 1 },
                      { 1, 0 },  { 1, -1 }, { 0, -1 }, { -1, -1 } };

    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

    queue<tuple<int, int, int>> p;
    p.push({ 0, 0, 1 });
    grid[0][0] = 1;

    while (!p.empty()) {
        int i = get<0>(p.front());
        int j = get<1>(p.front());
        int step = get<2>(p.front());

        if (i == n - 1 && j == n - 1) return step;

        for (int a = 0; a < 8; a++) {
            if (i + dir[a][0] >= 0 && i + dir[a][0] < n && j + dir[a][1] >= 0 &&
                j + dir[a][1] < n && !grid[i + dir[a][0]][j + dir[a][1]]) {
                p.push({ i + dir[a][0], j + dir[a][1], step + 1 });
                grid[i + dir[a][0]][j + dir[a][1]] = 1;
            }
        }

        p.pop();
    }
    return -1;
}

// 通过 | 40ms | 22.92MB
// O(m*n) | O(m*n)
// 逐渐掌握bfs的精髓（不过这也只是冰山一角）。
// 第一次使用了方向数组，莫名好用。