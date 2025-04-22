#pragma once

#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<int> merge = newInterval;
    vector<vector<int>> ans;
    for (vector<int>& x : intervals) {
        if (x[1] < merge[0]) {
            ans.push_back(x);
            continue;
        }
        if (x[0] > merge[1]) {
            if (!merge.empty()) {
                ans.push_back(merge);
                merge.clear();
            }
            ans.push_back(x);
            continue;
        }
        if (x[1] >= merge[0] || x[0] <= merge[1]) {
            merge[0] = min(merge[0], x[0]);
            merge[1] = max(merge[1], x[1]);
        }
    }
    if (!merge.empty()) ans.push_back(merge);
    return ans;
}

// 通过 | 0ms | 20.38MB
// O(n) | O(1)