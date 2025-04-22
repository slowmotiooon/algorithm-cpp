#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n;

    vector<int> nums(n);
    for (int& x : nums) cin >> x;
    cin >> k;
    vector<int> ans = maxSlidingWindow(nums, k);
    for (int x : ans) cout << x << ' ';
    cout << endl;
    return 0;
}

// https://leetcode.cn/problems/sliding-window-maximum