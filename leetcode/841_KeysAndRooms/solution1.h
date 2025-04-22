#pragma once
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& rooms, int current, vector<bool>& visited, int& counter) {
    if (visited[current]) return;
    visited[current] = true;
    counter++;
    for (int x : rooms[current]) dfs(rooms, x, visited, counter);
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vector<bool> visited(n);
    int counter = 0;
    dfs(rooms, 0, visited, counter);
    return counter == n;
}

// 通过 | 0ms | 14.16MB
// O(n+m) | O(n)
// 标准的深度优先搜索。