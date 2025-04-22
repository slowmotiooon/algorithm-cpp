#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    vector<vector<int>> queries(k, vector<int>(2));
    for (int& x : nums) cin >> x;
    for (vector<int>& x : queries) cin >> x[0] >> x[1];

    vector<bool> ans = isArraySpecial(nums, queries);

    for (bool x : ans) cout << x << ' ';
    return 0;
}

// https://leetcode.cn/problems/special-array-ii    1523