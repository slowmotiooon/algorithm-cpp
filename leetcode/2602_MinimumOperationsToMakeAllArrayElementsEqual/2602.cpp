#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> nums(n), queries(q);
    for (int& x : nums) cin >> x;
    for (int& x : queries) cin >> x;

    vector<long long> ans = minOperations(nums, queries);
    for (long long x : ans) cout << x << ' ';
    cout << endl;
    return 0;
}

// https://leetcode.cn/problems/minimum-operations-to-make-all-array-elements-equal     1903