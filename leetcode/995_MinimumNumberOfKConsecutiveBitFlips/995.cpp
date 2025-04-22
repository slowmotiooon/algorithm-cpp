#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& x : nums) cin >> x;

    int k;
    cin >> k;

    cout << minKBitFlips(nums, k) << endl;
    return 0;
}

// https://leetcode.cn/problems/minimum-number-of-k-consecutive-bit-flips       1835