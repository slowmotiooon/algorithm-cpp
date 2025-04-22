#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& x : nums) cin >> x;

    cout << maximumTripletValue(nums) << endl;
    return 0;
}

// https://leetcode.cn/problems/maximum-value-of-an-ordered-triplet-ii/description/     1583