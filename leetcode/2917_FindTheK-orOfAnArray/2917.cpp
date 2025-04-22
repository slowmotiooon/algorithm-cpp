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

    cout << findKOr(nums, k) << endl;
    return 0;
}

// https://leetcode.cn/problems/find-the-k-or-of-an-array/description/      1389