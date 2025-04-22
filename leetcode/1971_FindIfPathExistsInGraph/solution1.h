#pragma once

#include <vector>
using namespace std;

bool dfs(vector<vector<int>>& adj, int source, int destination, vector<bool>& visited) {
    if (source == destination) { return true; }
    visited[source] = true;

    for (auto& x : adj[source]) {
        if (!visited[x] && dfs(adj, x, destination, visited)) return true;
    }

    return false;
}

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    bool ans = false;
    vector<vector<int>> adj(n);
    for (auto& l : edges) {
        adj[l[0]].push_back(l[1]);
        adj[l[1]].push_back(l[0]);
    }
    vector<bool> visited(n, false);

    return dfs(adj, source, destination, visited);
}

// 通过 | 374ms | 291.58MB
// O(V+E) | O(V+E) V指顶点个数， E指边的个数
