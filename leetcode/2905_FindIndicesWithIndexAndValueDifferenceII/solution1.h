#pragma once

#include <climits>
#include <vector>
using namespace std;

vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
    int n = nums.size();
    int maxIndex = 0, minIndex = 0;
    for (int i = indexDifference; i < n; i++) {
        if (nums[maxIndex] > nums[i - indexDifference]) maxIndex = i - indexDifference;
        if (nums[minIndex] < nums[i - indexDifference]) minIndex = i - indexDifference;
        if (abs(nums[i] - nums[maxIndex]) >= valueDifference) return { i, maxIndex };
        if (abs(nums[i] - nums[minIndex]) >= valueDifference) return { i, minIndex };
    }
    maxIndex = n - 1;
    minIndex = n - 1;
    for (int i = n - 1 - indexDifference; i >= 0; i--) {
        if (nums[maxIndex] > nums[i + indexDifference]) maxIndex = i + indexDifference;
        if (nums[minIndex] < nums[i + indexDifference]) minIndex = i + indexDifference;
        if (abs(nums[i] - nums[maxIndex]) >= valueDifference) return { i, maxIndex };
        if (abs(nums[i] - nums[minIndex]) >= valueDifference) return { i, minIndex };
    }
    return { -1, -1 };
}

// 通过 | 7ms | 81.07MB
// O(n) | O(1)
// 两次循环，分别查找nums[i]右侧和左侧符合条件的值