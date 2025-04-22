#pragma once

#include <vector>
using namespace std;

int xorBeauty(vector<int>& nums) {
    int ans = 0;
    for (int i : nums) {
        for (int j : nums) {
            for (int k : nums) {
                ans ^= ((i | j) & k);
            }
        }
    }
    return ans;
}

// 超出时间限制
// O(n^3)算法，绝壁超时