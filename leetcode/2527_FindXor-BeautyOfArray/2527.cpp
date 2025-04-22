#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& x : nums) cin >> x;

    cout << xorBeauty(nums) << endl;
    return 0;
}

// https://leetcode.cn/problems/find-xor-beauty-of-array/description/       1550