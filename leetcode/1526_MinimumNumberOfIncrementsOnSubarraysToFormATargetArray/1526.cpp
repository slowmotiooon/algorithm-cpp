#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> target(n);
    for (int& x : target) cin >> x;

    cout << minNumberOperations(target) << endl;
    return 0;
}

// https://leetcode.cn/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array
// 1872