#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& x : nums) cin >> x;

    cout << maximumXOR(nums) << endl;
    return 0;
}

// https://leetcode.cn/problems/maximum-xor-after-operations/description/       1679