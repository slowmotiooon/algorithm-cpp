#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    for (vector<int>& x : intervals) cin >> x[0] >> x[1];

    cout << minGroups(intervals) << endl;
    return 0;
}

// https://leetcode.cn/problems/divide-intervals-into-minimum-number-of-groups      1713