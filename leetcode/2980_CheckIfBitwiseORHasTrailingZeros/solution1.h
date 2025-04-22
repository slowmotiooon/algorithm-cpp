#pragma once

#include <vector>
using namespace std;

bool hasTrailingZeros(vector<int>& nums) {
    int count = 0;
    for (int x : nums) {
        if (x == count) continue;
        if (!(x & 1)) {
            if (count == 0)
                count = x;
            else
                return true;
        }
    }
    return false;
}

// 通过 | 7ms | 27，81MB
// O(n) | O(1)
