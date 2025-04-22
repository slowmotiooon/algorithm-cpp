#pragma once

#include <vector>
using namespace std;

class RangeFreqQuery {
public:
    vector<int> nums;

    RangeFreqQuery(vector<int>& arr) {
        nums = arr;
    }

    int query(int left, int right, int value) {
        int ans = 0;
        for (int i = left; i <= right; i++) if (nums[i] == value) ans++;
        return ans;
    }
};

// 超出时间限制
// 想都不用想。这是暴力枚举