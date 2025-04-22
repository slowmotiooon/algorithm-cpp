#pragma once

#include <vector>
using namespace std;

void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int p, int n) {
    if (visited[p]) return;
    visited[p] = true;
    for (int i = 0; i < n; i++) {
        if (isConnected[i][p]) dfs(isConnected, visited, i, n);
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<bool> visited(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(isConnected, visited, i, n);
            ans++;
        }
    }
    return ans;
}

// 通过 | 21ms | 17.98MB
// O(n^2) | O(n)