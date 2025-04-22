#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n;

    vector<int> nums(n);
    for (int& x : nums) cin >> x;
    cin >> k;

    cout << maximumSubarraySum(nums, k) << endl;
    return 0;
}

// https://leetcode.cn/problems/maximum-good-subarray-sum       1817