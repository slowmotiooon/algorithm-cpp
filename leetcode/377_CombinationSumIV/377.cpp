#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& x : nums) cin >> x;

    int target;
    cin >> target;

    cout << combinationSum4(nums, target) << endl;
    return 0;
}

// https://leetcode.cn/problems/combination-sum-iv