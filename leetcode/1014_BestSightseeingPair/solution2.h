#pragma once

#include <climits>
#include <vector>
using namespace std;

int maxScoreSightseeingPair(vector<int>& values) {
    int n = values.size();
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (i != 0) max2 = max(max2, max1 + values[i] - i);
        if (i != n - 1) max1 = max(max1, values[i] + i);
    }
    return max2;
}

// 通过 | 32ms | 42.33MB
// O(n) | O(1)