#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;

    vector<int> nums(k);
    for (int& x : nums) cin >> x;

    int n, left, right;
    cin >> n >> left >> right;

    cout << rangeSum(nums, n, left, right) << endl;
    return 0;
}

// https://leetcode.cn/problems/range-sum-of-sorted-subarray-sums       1402