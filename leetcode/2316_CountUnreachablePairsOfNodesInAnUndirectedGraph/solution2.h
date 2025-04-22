#pragma once
#include <queue>
#include <vector>
using namespace std;

long long countPairs(int n, vector<vector<int>>& edges) {
    long long total = (long long)n * (n - 1);
    long long counter = 0;
    vector<vector<int>> table(n, vector<int>());
    for (auto& x : edges) {
        if (x[0] < x[1])
            table[x[0]].push_back(x[1]);
        else
            table[x[1]].push_back(x[0]);
    }
    for (int i = 0; i < n; i++) {
        queue<int> points;
        vector<bool> visited(n, false);
        points.push(i);
        while (!points.empty()) {
            int current = points.front();
            if (visited[current]) {
                points.pop();
                continue;
            }
            if (current > i) counter++;
            visited[current] = true;
            for (int x : table[current])
                if (!visited[x]) points.push(x);
            points.pop();
        }
    }
    return (total - counter) / 2;
}

// 不能用广度优先搜索？