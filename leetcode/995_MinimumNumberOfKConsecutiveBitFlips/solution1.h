#pragma once

#include <vector>
using namespace std;

int minKBitFlips(vector<int>& nums, int k) {
    int counter = 0;
    int n = nums.size();
    for (int i = 0; i <= n - k; i++) {
        if (nums[i] == 0) {
            for (int j = 0; j < k; j++) {
                nums[i + j] = (nums[i + j] ? 0 : 1);
            }
            counter++;
        }
    }
    for (int i = n - k + 1; i < n; i++) {
        if (nums[i] == 0) return -1;
    }
    return counter;
}

// 超出时间限制
// 原因：在识别到0后做的反转的时间复杂度是O(k)，使得总时间复杂度成为O(kn)