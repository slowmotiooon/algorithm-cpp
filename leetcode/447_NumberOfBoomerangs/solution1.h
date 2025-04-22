#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

int numberOfBoomerangs(vector<vector<int>>& points) {
    if (points.size() < 3) return 0;
    int ans = 0;
    for (int i = 0; i < points.size(); i++) {
        unordered_map<int, int> counter;
        for (int j = 0; j < points.size(); j++) {
            int d = (points[j][0] - points[i][0]) * (points[j][0] - points[i][0]) +
                    (points[j][1] - points[i][1]) * (points[j][1] - points[i][1]);
            counter[d]++;
        }
        for (auto it : counter) {
            ans += it.second * (it.second - 1);
        }
    }
    return ans;
}

// 通过 | 428ms | 125.09MB
// O(n^2) | O(n)