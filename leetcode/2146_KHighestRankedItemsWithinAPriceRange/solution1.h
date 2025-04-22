#pragma once

#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing,
                                        vector<int>& start, int k) {
    int m = grid.size();
    int n = grid[0].size();
    queue<tuple<int, int, int>> q;
    vector<tuple<int, int, int, int>> info;   // i,j,step,price
    vector<vector<int>> ans;
    int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    q.push({ start[0], start[1], 0 });
    if (grid[start[0]][start[1]] >= pricing[0] && grid[start[0]][start[1]] <= pricing[1])
        info.push_back({ start[0], start[1], 0, grid[start[0]][start[1]] });
    grid[start[0]][start[1]] = 0;

    auto compare = [](tuple<int, int, int, int>& x, tuple<int, int, int, int>& y) {
        if (get<2>(x) != get<2>(y))
            return get<2>(x) < get<2>(y);
        else if (get<3>(x) != get<3>(y))
            return get<3>(x) < get<3>(y);
        else if (get<0>(x) != get<0>(y))
            return get<0>(x) < get<0>(y);
        else
            return get<1>(x) < get<1>(y);
    };

    while (!q.empty()) {
        int i = get<0>(q.front());
        int j = get<1>(q.front());
        int s = get<2>(q.front());

        for (int a = 0; a < 4; a++) {
            int newi = i + dir[a][0];
            int newj = j + dir[a][1];
            if (newi >= 0 && newi < m && newj >= 0 && newj < n && grid[newi][newj] != 0) {
                if (grid[newi][newj] >= pricing[0] && grid[newi][newj] <= pricing[1]) {
                    info.push_back({ newi, newj, s + 1, grid[newi][newj] });
                }
                q.push({ newi, newj, s + 1 });
                grid[newi][newj] = 0;
            }
        }

        q.pop();
    }

    sort(info.begin(), info.end(), compare);

    for (int i = 0; i < (k < info.size() ? k : info.size()); i++)
        ans.push_back({ get<0>(info[i]), get<1>(info[i]) });
    return ans;
}

// 通过 | 315ms | 169.13MB
// O(m*n) | O(m*n)
//