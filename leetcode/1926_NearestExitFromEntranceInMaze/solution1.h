#pragma once

#include <queue>
#include <vector>
using namespace std;

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int m = maze.size();
    int n = maze[0].size();
    queue<vector<int>> d;
    d.push(entrance);
    d.back().push_back(0);

    while (!d.empty()) {
        vector<int> current = d.front();

        if (current[0] != entrance[0] || current[1] != entrance[1]) {
            if (current[0] == 0 || current[1] == 0 || current[0] == m - 1 || current[1] == n - 1)
                return current[2];
        }

        if (current[0] != 0 && maze[current[0] - 1][current[1]] != '+')
            d.push({ current[0] - 1, current[1], current[2] + 1 });
        if (current[0] != m - 1 && maze[current[0] + 1][current[1]] != '+')
            d.push({ current[0] + 1, current[1], current[2] + 1 });
        if (current[1] != 0 && maze[current[0]][current[1] - 1] != '+')
            d.push({ current[0], current[1] - 1, current[2] + 1 });
        if (current[1] != n - 1 && maze[current[0]][current[1] + 1] != '+')
            d.push({ current[0], current[1] + 1, current[2] + 1 });

        maze[current[0]][current[1]] = '+';
        d.pop();
    }
    return -1;
}

// 超出时间限制