#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& x : nums) cin >> x;

    cout << subsetXORSum(nums);
    return 0;
}

// https://leetcode.cn/problems/sum-of-all-subset-xor-totals/description/       1372