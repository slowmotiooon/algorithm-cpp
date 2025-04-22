#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ans = countBits(n);
    for (int i : ans) cout << i << ' ';
    return 0;
}

// https://leetcode.cn/problems/counting-bits/description/