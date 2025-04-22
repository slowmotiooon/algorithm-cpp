#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> pushed(n), poped(n);
    for (int& x : pushed) cin >> x;
    for (int& x : poped) cin >> x;

    cout << validateStackSequences(pushed, poped) << endl;
    return 0;
}

// https://leetcode.cn/problems/validate-stack-sequences        1462