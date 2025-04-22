#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

int minSumOfLengths(vector<int>& arr, int target) {
    int n = arr.size();
    vector<int> sum(n + 1, 0);
    for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + arr[i];
    unordered_map<int, int> index, diff;
    int minDiff = __INT_MAX__;
    for (int i = 0; i <= n; i++) {
        if (index.find(sum[i]) != index.end()) {
            diff[i - index[sum[i]]]++;
            minDiff = min(minDiff, i - index[sum[i]]);
        }
        index[sum[i] + target]++;
    }
    return diff[minDiff] * minDiff;
}