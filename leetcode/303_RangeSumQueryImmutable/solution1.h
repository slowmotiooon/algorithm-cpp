#pragma once

#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> nums;

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
    }

    int sumRange(int left, int right) {
        int sum = 0;
        for (int i = left; i <= right; i++) {
            sum += nums[i];
        }
        return sum;
    }
};

// 运行结果：
// 通过 | 226ms | 21.45MB
// O(1) | O(n)      NumArray(vector<int>& nums)
// O(n) | O(n)      int sumRange(int left, int right)
// 常规方法。能通过但是慢。