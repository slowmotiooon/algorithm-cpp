#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<vector<int>> queries(n, vector<int>(3));
    for (vector<int>& x : queries) cin >> x[0] >> x[1] >> x[2];

    vector<bool> ans = canMakePaliQueries(s, queries);
    for (bool x : ans) cout << x << " ";
    cout << endl;
    return 0;
}

// https://leetcode.cn/problems/can-make-palindrome-from-substring      1848