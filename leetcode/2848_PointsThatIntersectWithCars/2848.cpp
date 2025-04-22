#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> nums(n, vector<int>(2));
    for (vector<int>& x : nums) cin >> x[0] >> x[1];

    cout << numberOfPoints(nums) << endl;
    return 0;
}

// https://leetcode.cn/problems/points-that-intersect-with-cars     1230