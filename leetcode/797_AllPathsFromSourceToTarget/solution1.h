#pragma once

#include <vector>
using namespace std;

vector<int> path = {};
vector<vector<int>> result;

void dfs(vector<vector<int>> graph, int index) {
    path.push_back(index);
    if (index == graph.size() - 1) {
        result.push_back(path);
        path.pop_back();
        return;
    }
    for (int x : graph[index]) dfs(graph, x);
    path.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    dfs(graph, 0);
    return result;
}

// 通过 | 157ms | 51.30MB
// O(n*2^n) | O(n)
