#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& x : nums) cin >> x;

    cout << maximumSum(nums) << endl;
    return 0;
}

// https://leetcode.cn/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/     1309