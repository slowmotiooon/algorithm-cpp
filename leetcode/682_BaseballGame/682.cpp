#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> op(n);
    for (string& x : op) cin >> x;

    cout << calPoints(op) << endl;
    return 0;
}

// https://leetcode.cn/problems/baseball-game