#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int& x : arr) cin >> x;

    int k;
    cin >> k;

    vector<vector<int>> quiries(k, vector<int>(2));
    for (vector<int>& x : quiries) cin >> x[0] >> x[1];

    vector<int> ans = xorQueries(arr, quiries);
    for (int x : ans) cout << x << ' ';
    cout << endl;
    return 0;
}

// https://leetcode.cn/problems/xor-queries-of-a-subarray/description/      1460