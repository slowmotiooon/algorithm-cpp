#pragma once

#include <vector>
using namespace std;

bool hasTrailingZeros(vector<int>& nums) {
    bool hasEven = false;
    for (int x : nums) {
        if (!(x & 1)) {
            if (hasEven)
                return true;
            else
                hasEven = true;
        }
    }
    return false;
}

// 通过 | 11ms | 27.75MB
// O(n) | O(1)
