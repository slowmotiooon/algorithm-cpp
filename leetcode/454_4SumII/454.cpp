#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums1(n), nums2(n), nums3(n), nums4(n);
    for (int& x : nums1) cin >> x;
    for (int& x : nums2) cin >> x;
    for (int& x : nums3) cin >> x;
    for (int& x : nums4) cin >> x;

    cout << fourSumCount(nums1, nums2, nums3, nums4) << endl;
    return 0;
}

// https://leetcode.cn/problems/4sum-ii/description/