#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;

    vector<int> targets(k);
    for (int& x : targets) cin >> x;

    int n;
    cin >> n;

    vector<string> ans = buildArray(targets, n);
    for (string x : ans) cout << x << " ";
    return 0;
}

// https://leetcode.cn/problems/build-an-array-with-stack-operations        1180
