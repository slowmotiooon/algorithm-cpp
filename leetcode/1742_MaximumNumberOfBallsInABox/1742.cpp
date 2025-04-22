#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int lowLimit, highLimit;
    cin >> lowLimit >> highLimit;

    cout << countBalls(lowLimit, highLimit) << endl;
    return 0;
}

// https://leetcode.cn/problems/maximum-number-of-balls-in-a-box 1278