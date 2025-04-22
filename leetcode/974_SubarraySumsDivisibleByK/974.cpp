#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n;

    vector<int> nums(n);
    for (int& x : nums) cin >> x;

    cin >> k;
    cout << subarraysDivByK(nums, k) << endl;
    return 0;
}

// https://leetcode.cn/problems/subarray-sums-divisible-by-k        1676