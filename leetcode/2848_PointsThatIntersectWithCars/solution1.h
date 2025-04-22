#pragma once

#include <climits>
#include <vector>
using namespace std;

int numberOfPoints(vector<vector<int>>& nums) {
    int begin = INT_MAX, end = INT_MIN;
    for (vector<int> x : nums) {
        begin = min(begin, x[0]);
        end = max(end, x[1]);
    }
    vector<int> diff(end + 2, 0);
    for (vector<int> x : nums) {
        diff[x[0]]++;
        diff[x[1] + 1]--;
    }
    int intersection = 0;
    int ans = 0;
    for (int i = begin; i <= end; i++) {
        intersection += diff[i];
        if (intersection != 0) ans++;
    }
    return ans;
}

// 通过 | 11ms | 29.68MB
// O(n+l) | O(l)
// 差分数组题。