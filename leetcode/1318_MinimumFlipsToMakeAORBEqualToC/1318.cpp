#include "solution2.h"
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << minFlips(a, b, c) << endl;
    return 0;
}

// https://leetcode.cn/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/        1383