#pragma once

#include <vector>
using namespace std;

int maximumPopulation(vector<vector<int>>& logs) {
    int early = 0x7fffffff, late = 0x80000000;
    for (auto& x : logs) {
        early = min(early, x[0]);
        late = max(late, x[1]);
    }
    vector<int> diff(late - early + 2, 0);
    for (auto& x : logs) {
        diff[x[0] - early]++;
        diff[x[1] - early]--;
    }
    int maxv = 0x80000000;
    int val = 0;
    int maxy = early;
    for (int i = 0; i < diff.size(); i++) {
        val += diff[i];
        if (val > maxv) {
            maxv = val;
            maxy = i + early;
        }
    }
    return maxy;
}

// 通过 | 0ms | 10.09MB
// O(n+l) | O(l)