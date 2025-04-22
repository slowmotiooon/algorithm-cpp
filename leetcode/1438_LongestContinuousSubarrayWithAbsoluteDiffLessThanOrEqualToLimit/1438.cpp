#include "solution2.h"
#include <iostream>
using namespace std;

int main() {
    int n, limit;
    cin >> n;

    vector<int> nums(n);
    for (int& x : nums) cin >> x;

    cin >> limit;

    cout << longestSubarray(nums, limit) << endl;
    return 0;
}

// https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit