#pragma once

#include <algorithm>
#include <vector>
using namespace std;

int rangeSum(vector<int>& nums, int n, int left, int right) {
    sort(nums.begin(), nums.end());
    vector<int> sums(nums.size() + 1);
    for (int i = 0; i < nums.size(); i++) sums[i + 1] = sums[i] + nums[i];
    return sums[right] - sums[left];
}