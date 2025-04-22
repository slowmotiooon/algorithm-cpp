#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& x : nums) cin >> x;

    cout << singleNumber(nums) << endl;
    return 0;
}

// https://leetcode.cn/problems/single-number/description/