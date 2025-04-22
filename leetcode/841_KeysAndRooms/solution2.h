#pragma once
#include <queue>
#include <vector>
using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vector<bool> visited(n);
    queue<int> q;
    int counter = 0;
    q.push(0);
    while (!q.empty()) {
        int current = q.front();
        if (!visited[current]) {
            visited[current] = true;
            counter++;
            for (int x : rooms[current]) q.push(x);
        }
        q.pop();
    }

    return counter == n;
}

// 通过 | 0ms | 14.19MB
// O(n+m) | O(n)
// 广度优先搜索