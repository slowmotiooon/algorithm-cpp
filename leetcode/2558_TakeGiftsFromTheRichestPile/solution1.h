#pragma once

#include <numeric>
#include <queue>
#include <vector>
using namespace std;

long long pickGifts(vector<int>& gifts, int k) {
    priority_queue<int> q;
    for (int x : gifts) q.push(x);
    for (int i = 0; i < k; i++) {
        int val = (int)sqrt(q.top());
        q.pop();
        q.push(val);
    }
    long long ans = 0;
    while (!q.empty()) {
        ans += (long long)q.top();
        q.pop();
    }
    return ans;
}

// 通过 | 0ms | 12.70MB
// O(n+k) | O(n)