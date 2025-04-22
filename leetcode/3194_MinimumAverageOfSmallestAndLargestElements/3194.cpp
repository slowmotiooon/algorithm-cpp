#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& x : nums) cin >> x;

    cout << minimumAverage(nums) << endl;
    return 0;
}

// https://leetcode.cn/problems/minimum-average-of-smallest-and-largest-elements/description/?envType=daily-question&envId=2024-10-16
// 1195