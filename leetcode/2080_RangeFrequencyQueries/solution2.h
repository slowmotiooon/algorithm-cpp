#pragma once

#include <vector>
#include <algorithm>
using namespace std;

class RangeFreqQuery {
public:
    vector<int> nums;

    RangeFreqQuery(vector<int>& arr) {
        nums = arr;
        sort(nums.begin(), nums.end());
    }

    int query(int left, int right, int value) {
        int start = left, end1 = right + 1;
        while (start < end1) {
            int mid = start + (end1 - start) / 2;
            if (nums[mid] > value) end1 = mid;
            else start = mid + 1;
        }
        start = left;
        int end2 = right + 1;
        while (start < end2) {
            int mid = start + (end2 - start) / 2;
            if (nums[mid] >= value) end2 = mid;
            else left = mid + 1;
        }
        return end1 - end2;
    }
};

// 超出时间限制
// 其实这个算法是错误的。因为要求特定范围，所以不能对源数组排序。