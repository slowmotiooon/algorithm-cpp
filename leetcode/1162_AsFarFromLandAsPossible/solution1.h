#pragma once

#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int maxDistance(vector<vector<int>>& grid) {
    int n = grid.size();
    int sum = 0;
    queue<tuple<int, int, int>> q;
    int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += grid[i][j];
            if (grid[i][j]) q.push({ i, j, 0 });
        }
    }
    if (sum == n * n || sum == 0) return -1;

    while (!q.empty()) {
        int i = get<0>(q.front());
        int j = get<1>(q.front());
        int step = get<2>(q.front());
        for (int a = 0; a < 4; a++) {
            if (i + dir[a][0] >= 0 && i + dir[a][0] < n && j + dir[a][1] >= 0 &&
                j + dir[a][1] < n && !grid[i + dir[a][0]][j + dir[a][1]]) {
                q.push({ i + dir[a][0], j + dir[a][1], step + 1 });
                grid[i + dir[a][0]][j + dir[a][1]] = 1;
                ans = step + 1;
            }
        }
        q.pop();
    }
    return ans;
}

// 通过 | 40ms | 23.68MB
// O(m*n) | O(m*n)
// 一看到题解标题上写着多源BFS就知道怎么做了。