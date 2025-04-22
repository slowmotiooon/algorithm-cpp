#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> pref(n);
    for (int& x : pref) cin >> x;

    vector<int> ans = findArray(pref);
    for (int x : ans) cout << x << ' ';
    cout << endl;
    return 0;
}

// https://leetcode.cn/problems/find-the-original-array-of-prefix-xor/description/      1367