#pragma once

#include <vector>
using namespace std;

int maxSubarrays(vector<int>& nums) {
    int count = 0;
    int current = nums[0];
    for (int x : nums) {
        current &= x;
        if (current == 0) {
            count++;
            current = 0xffffffff;
        }
    }
    return count == 0 ? 1 : count;
}

// 通过 | 113ms | 105.98MB
// O(n) | O(1)