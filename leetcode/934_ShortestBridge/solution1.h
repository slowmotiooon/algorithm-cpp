#pragma once

#include <queue>
#include <tuple>
#include <vector>
using namespace std;


int m, n;

void dfs(vector<vector<int>>& grid, int i, int j, queue<tuple<int, int, int>>& q) {

    grid[i][j] = 2;
    q.push({ i, j, 0 });

    if (i > 0 && grid[i - 1][j] == 1) dfs(grid, i - 1, j, q);
    if (i < m - 1 && grid[i + 1][j] == 1) dfs(grid, i + 1, j, q);
    if (j > 0 && grid[i][j - 1] == 1) dfs(grid, i, j - 1, q);
    if (j < n - 1 && grid[i][j + 1] == 1) dfs(grid, i, j + 1, q);
}

int shortestBridge(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    int start[2] = { -1, -1 };
    int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    queue<tuple<int, int, int>> q;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                start[0] = i;
                start[1] = j;
                break;
            }
        }
        if (start[0] != -1) break;
    }

    dfs(grid, start[0], start[1], q);

    while (!q.empty()) {
        int i = get<0>(q.front());
        int j = get<1>(q.front());
        int s = get<2>(q.front());

        for (int a = 0; a < 4; a++) {
            if (i + dir[a][0] >= 0 && i + dir[a][0] < m && j + dir[a][1] >= 0 &&
                j + dir[a][1] < n) {
                if (grid[i + dir[a][0]][j + dir[a][1]] == 0) {
                    q.push({ i + dir[a][0], j + dir[a][1], s + 1 });
                    grid[i + dir[a][0]][j + dir[a][1]] = 2;
                }
                else if (grid[i + dir[a][0]][j + dir[a][1]] == 1)
                    return s;
            }
        }
        q.pop();
    }
    return -1;
}

// 通过 | 40ms | 24.13MB
// O(m*n) | O(m*n)
// BFS+DFS，DFS找一个小岛，然后用多源BFS找最短桥