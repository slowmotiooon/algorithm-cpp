#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& x : nums) cin >> x;

    vector<int> ans = asteroidCollision(nums);
    for (int x : ans) cout << x << ' ';
    cout << endl;
    return 0;
}

// https://leetcode.cn/problems/asteroid-collision