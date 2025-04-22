#pragma once

#include <vector>
using namespace std;

bool isCovered(vector<vector<int>>& ranges, int left, int right) {

    vector<int> diff(52, 0);
    for (vector<int> x : ranges) {
        diff[x[0]]++;
        diff[x[1] + 1]--;
    }
    int val = 0;
    for (int i = 1; i <= 51; i++) {
        val += diff[i];
        if (!val && i >= left && i <= right) return false;
    }
    return true;
}

// 通过 | 0ms | 11.31MB
// O(n+Σ) | O(Σ) Σ=52
// 经典差分