#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n, target;
    cin >> n;

    vector<int> arr(n);
    for (int& x : arr) cin >> x;

    cin >> target;
    cout << minSumOfLengths(arr, target) << endl;
    return 0;
}

// https://leetcode.cn/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum        1851