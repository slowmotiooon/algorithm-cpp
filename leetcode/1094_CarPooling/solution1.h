#pragma once

#include <vector>
using namespace std;

bool carPooling(vector<vector<int>>& trips, int capacity) {
    int maxTo = 0;
    for (vector<int> t : trips) maxTo = max(maxTo, t[2]);
    vector<int> diff(maxTo + 1);
    for (vector<int> x : trips) {
        diff[x[1]] += x[0];
        diff[x[2]] -= x[0];
    }
    int begin = 0;
    for (int x : diff) {
        begin += x;
        if (begin > capacity) return false;
    }
    return true;
}

// 通过 | 0ms | 13.85MB
// O(n+l) | O(l)