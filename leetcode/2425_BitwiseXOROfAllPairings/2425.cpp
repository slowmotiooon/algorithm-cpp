#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> nums1(m), nums2(n);
    for (int& x : nums1) cin >> x;
    for (int& x : nums2) cin >> x;

    cout << xorAllNums(nums1, nums2) << endl;
    return 0;
}

// https://leetcode.cn/problems/bitwise-xor-of-all-pairings/description/        1622