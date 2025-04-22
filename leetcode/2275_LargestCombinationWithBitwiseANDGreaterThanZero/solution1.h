#pragma once

#include <algorithm>
#include <vector>
using namespace std;

int largestCombination(vector<int>& candidates) {
    vector<int> counter(24, 0);
    for (int x : candidates) {
        for (int i = 0; i < 24; i++) counter[i] += ((x >> i) & 1);
    }
    return *max_element(counter.begin(), counter.end());
}

// 通过 | 93ms | 58.81MB
// O(n*log(m)) m为题目范围最大值(2^24) | O(1)