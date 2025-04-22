#pragma once

#include <algorithm>
#include <vector>
using namespace std;

inline void dfs(vector<vector<int>>& land, int i, int j, int& area) {
    if (i < 0 || j < 0 || i >= land.size() || j >= land[0].size() || land[i][j] != 0) return;

    area++;
    land[i][j]--;

    dfs(land, i - 1, j, area);       // up
    dfs(land, i + 1, j, area);       // down
    dfs(land, i, j - 1, area);       // left
    dfs(land, i, j + 1, area);       // right
    dfs(land, i - 1, j - 1, area);   // upleft
    dfs(land, i - 1, j + 1, area);   // upright
    dfs(land, i + 1, j + 1, area);   // downright
    dfs(land, i + 1, j - 1, area);   // downleft
}

inline vector<int> pondSizes(vector<vector<int>>& land) {
    vector<int> ans;
    int         area = 0;
    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < land[0].size(); j++) {
            if (land[i][j] == 0) {
                area = 0;
                dfs(land, i, j, area);
                ans.push_back(area);
            }
        }
    }

    sort(ans.begin(), ans.end());

    return ans;
}

// 通过 | 84ms | 33.99MB
// O(m*n) | O(m*n)
// 岛屿面积强化版，只是多了4个方向。
