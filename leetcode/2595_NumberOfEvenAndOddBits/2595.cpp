#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ans = evenOddBit(n);
    cout << ans[0] << ans[1] << endl;
    return 0;
}

// https://leetcode.cn/problems/number-of-even-and-odd-bits/description/        1207