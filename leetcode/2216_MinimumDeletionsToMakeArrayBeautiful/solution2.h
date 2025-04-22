#pragma once

#include <vector>
using namespace std;

int minDeletion(vector<int>& nums) {
    vector<int> mod;
    for (int x : nums) {
        if (mod.size() % 2 != 0 && x == mod.back()) continue;
        mod.push_back(x);
    }
    if (mod.size() % 2 != 0) return nums.size() - mod.size() - 1;
    return nums.size() - mod.size();
}

// 通过 | 4ms | 129.64MB
// O(n) | O(n)
