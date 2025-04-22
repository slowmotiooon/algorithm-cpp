#pragma once

#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

long long maximumTripletValue(vector<int>& nums) {
    int n = nums.size();
    int minIndex = n - 1;
    int maxVal = INT_MIN;
    int maxIndex = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (i != n - 1) {
            if (nums[i] - nums[minIndex] >= maxVal) {
                maxVal = nums[i] - nums[minIndex];
                maxIndex = i;
            }
        }
        if (i != 0)
            if (nums[i] <= nums[minIndex]) minIndex = i;
    }

    int mul = *max_element(nums.begin() + 1 + minIndex, nums.end());
    if (maxVal < 0)
        return 0;
    else
        return maxVal * mul;
}

// 解答错误