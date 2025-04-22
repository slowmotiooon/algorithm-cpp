#pragma once
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& table, int current, vector<bool>& visited, int& points) {
    if (visited[current]) return;
    points++;
    visited[current] = true;
    for (int x : table[current]) dfs(table, x, visited, points);
}

long long countPairs(int n, vector<vector<int>>& edges) {
    long long total = (long long)n * (n - 1) / 2;
    vector<bool> visited(n, false);
    vector<vector<int>> table(n, vector<int>());
    for (auto& x : edges) {
        table[x[0]].push_back(x[1]);
        table[x[1]].push_back(x[0]);
    }
    for (int i = 0; i < n; i++) {
        int points = 0;
        if (!visited[i]) {
            dfs(table, i, visited, points);
            total -= (long long)points * (points - 1) / 2;
        }
    }
    return total;
}

// 通过 | 146ms | 173.60MB
// O(n+m) | O(n+m) m为边数
// 使用深度优先搜索。之前的思路是数路径，但是有一个问题，就是不能重复利用已经数过的路径的子路径。比如有一条路径：1-3-2，使用数路径的方式一次只能知道1-2和1-3，但是要得到2-3，就得从2开始数路径。这样会极大增加时间复杂度。因此，此处使用的方法是数有几个点可以互相连通，然后根据公式计算路径数，这样可以有效提升计算速度。