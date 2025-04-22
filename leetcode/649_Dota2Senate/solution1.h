#pragma once

#include <queue>
#include <string>
using namespace std;

string predictPartyVictory(string senate) {
    queue<int> rq, dq;
    int n = senate.size();
    for (int i = 0; i < n; i++) senate[i] == 'R' ? rq.push(i) : dq.push(i);
    while (!rq.empty() && !dq.empty()) {
        if (rq.front() < dq.front()) {
            rq.push(rq.front() + n);
            dq.pop();
            rq.pop();
        }
        else {
            dq.push(dq.front() + n);
            rq.pop();
            dq.pop();
        }
    }
    return dq.empty() ? "Radiant" : "Dire";
}

// 通过 | 10ms | 11.43MB
// O(n) | O(n)