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

    cout << maxOperations(nums, k) << endl;
    return 0;
}

// https://leetcode.cn/problems/max-number-of-k-sum-pairs/description/      1346