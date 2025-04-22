#pragma once

#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int m = maze.size();
    int n = maze[0].size();

    queue<tuple<int, int, int>> q;
    q.push({ entrance[0], entrance[1], 0 });
    maze[entrance[0]][entrance[1]] = '+';

    while (!q.empty()) {
        int i = get<0>(q.front());
        int j = get<1>(q.front());
        int step = get<2>(q.front());

        if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
            if (i != entrance[0] || j != entrance[1]) return step;
        }

        if (i != 0 && maze[i - 1][j] != '+') {
            q.push({ i - 1, j, step + 1 });
            maze[i - 1][j] = '+';
        }
        if (i != m - 1 && maze[i + 1][j] != '+') {
            q.push({ i + 1, j, step + 1 });
            maze[i + 1][j] = '+';
        }
        if (j != 0 && maze[i][j - 1] != '+') {
            q.push({ i, j - 1, step + 1 });
            maze[i][j - 1] = '+';
        }
        if (j != n - 1 && maze[i][j + 1] != '+') {
            q.push({ i, j + 1, step + 1 });
            maze[i][j + 1] = '+';
        }

        q.pop();
    }

    return -1;
}

// 通过 | 97ms | 70.31MB
// O(m*n) | O(m*n)
// 思路来源：https://leetcode.cn/problems/nearest-exit-from-entrance-in-maze/solutions/869920/mi-gong-zhong-chi-ru-kou-zui-jin-de-chu-0ued5
// 需要注意：在得知下一节点有效后，在将其加入队列后应立即将其变为'+'，防止重复访问。