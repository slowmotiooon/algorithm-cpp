#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& x : nums) cin >> x;

    vector<int> ans = getSumAbsoluteDifferences(nums);
    for (int x : ans) cout << x << ' ';
    cout << '\n' << flush;
    return 0;
}

// https://leetcode.cn/problems/sum-of-absolute-differences-in-a-sorted-array       1496