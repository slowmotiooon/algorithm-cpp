#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n, k, m;
    cin >> n;

    vector<int> nums(n);
    for (int& x : nums) cin >> x;
    cin >> k >> m;

    vector<int> ans = getFinalState(nums, k, m);
    for (int x : ans) cout << x << ' ';
    cout << endl;
    return 0;
}

// https://leetcode.cn/problems/final-array-state-after-k-multiplication-operations-i 1178