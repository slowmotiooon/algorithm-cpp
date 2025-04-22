#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& x : nums) cin >> x;

    cout << hasTrailingZeros(nums) << endl;
    return 0;
}

// https://leetcode.cn/problems/check-if-bitwise-or-has-trailing-zeros/description/     1234