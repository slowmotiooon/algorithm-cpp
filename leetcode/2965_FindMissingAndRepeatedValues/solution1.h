#pragma once

#include <vector>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<int> counter(n * n + 1, 0);
    for (vector<int> line : grid)
        for (int x : line) counter[x]++;

    int dulp = 0, lost = 0;
    for (int i = 1; i < counter.size(); i++) {
        if (counter[i] == 0) lost = i;
        if (counter[i] == 2) dulp = i;
    }
    return { dulp, lost };
}

// 通过 | 22ms | 25.88MB
// O(n^2) | O(n^2)
// 一下子就能想到的做法。