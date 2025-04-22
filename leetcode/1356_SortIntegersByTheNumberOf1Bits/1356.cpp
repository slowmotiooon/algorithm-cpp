#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int& x : arr) cin >> x;

    vector<int> ans = sortByBits(arr);
    for (int x : ans) cout << x << ' ';
    cout << endl;
    return 0;
}

// https://leetcode.cn/problems/sort-integers-by-the-number-of-1-bits/description/