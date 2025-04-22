#pragma once

#include <vector>
using namespace std;

int findKOr(vector<int>& nums, int k) {
    int ans = 0;
    int map[32] = { 0 };

    for (int x : nums) {
        while (__builtin_popcount(x)) {
            map[__builtin_ctz(x)]++;
            x -= (1 << __builtin_ctz(x));
        }
    }
    for (int i = 0; i < 32; i++) {
        if (map[i] >= k) ans += (1 << i);
    }
    return ans;
}

// 通过 | 4ms | 28.76MB
// O(n*log(x)) | O(1)
// 这是横着数，需要维护数组，竖着数不用维护。