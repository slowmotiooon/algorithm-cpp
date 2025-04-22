#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    string s;
    int n;
    cin >> s >> n;

    vector<vector<int>> queries(n, vector<int>(2));
    for (vector<int>& x : queries) cin >> x[0] >> x[1];

    vector<int> ans = platesBetweenCandles(s, queries);
    for (int x : ans) cout << x << ' ';
    cout << endl;
    return 0;
}

// https://leetcode.cn/problems/plates-between-candles      1819