#pragma once

#include <queue>
using namespace std;

class RecentCounter
{
    queue<int> q;

public:
    RecentCounter() {
        while (!q.empty()) q.pop();
    }

    int ping(int t) {
        q.push(t);
        while (q.front() <= t - 3000) q.pop();
        return q.size();
    }
};

// 通过 | 27ms | 62.87MB
