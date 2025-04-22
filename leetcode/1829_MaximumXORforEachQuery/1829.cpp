#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& x : nums) cin >> x;

    int maximumBit;
    cin >> maximumBit;

    vector<int> ans = getMaximumXor(nums, maximumBit);
    for (int x : ans) cout << x << ' ';
    cout << endl;
    return 0;
}

// https://leetcode.cn/problems/maximum-xor-for-each-query/description/     1523