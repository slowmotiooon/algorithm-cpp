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

    vector<vector<int>> requests(k, vector<int>(2));
    for (vector<int>& x : requests) cin >> x[0] >> x[1];

    cout << maxSumRangeQuery(nums, requests) << endl;
    return 0;
}

// https://leetcode.cn/problems/maximum-sum-obtained-of-any-permutation     1871