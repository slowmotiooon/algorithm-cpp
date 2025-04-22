#pragma once

#include <climits>
#include <vector>
using namespace std;

int maxScoreSightseeingPair(vector<int>& values) {
    int n = values.size();
    int ans = INT_MIN;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = max(ans, values[i] + values[j] + i - j);
        }
    }
    return ans;
}

// 超出时间限制
// O(n^2) | O(1)