#pragma once

#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> sums;

public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for (int i : nums) {
            sum += i;
            sums.push_back(sum);
        }
    }

    int sumRange(int left, int right) {
        if (left == 0) return sums[right];
        else return sums[right] - sums[left - 1];
    }
};

// 运行结果：
// 通过 | 15ms | 21.64MB
// O(n) | O(n)      NumArray(vector<int>& nums)
// O(1) | O(n)      int sumRange(int left, int right)
// 在初始化时就将前缀和存储，避免多次调用sumRange函数耗时。