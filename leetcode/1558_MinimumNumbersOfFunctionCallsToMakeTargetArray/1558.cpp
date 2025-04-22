#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& x : nums) cin >> x;

    cout << minOperations(nums) << endl;
    return 0;
}

// https://leetcode.cn/problems/minimum-numbers-of-function-calls-to-make-target-array/description/
// 1637