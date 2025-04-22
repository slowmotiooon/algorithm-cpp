#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> candidates(n);
    for (int& x : candidates) cin >> x;

    cout << largestCombination(candidates) << endl;
    return 0;
}

// https://leetcode.cn/problems/largest-combination-with-bitwise-and-greater-than-zero/description/
// 1642