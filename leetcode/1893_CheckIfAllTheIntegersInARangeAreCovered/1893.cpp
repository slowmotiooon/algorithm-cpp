#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> ranges(n, vector<int>(2));
    for (vector<int>& x : ranges) cin >> x[0] >> x[1];

    int left, right;
    cin >> left >> right;

    cout << isCovered(ranges, left, right) << endl;
    return 0;
}

// https://leetcode.cn/problems/check-if-all-the-integers-in-a-range-are-covered        1307