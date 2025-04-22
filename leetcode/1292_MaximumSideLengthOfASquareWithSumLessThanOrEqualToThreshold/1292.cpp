#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int m, n, k;
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    for (vector<int>& l : mat)
        for (int& x : l) cin >> x;
    cin >> k;

    cout << maxSideLength(mat, k);
    return 0;
}

// https://leetcode.cn/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold
// 1735