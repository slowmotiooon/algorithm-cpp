#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int l, h, z, o;
    cin >> l >> h >> z >> o;
    cout << countGoodStrings(l, h, z, o) << endl;
    return 0;
}

// https://leetcode.cn/problems/count-ways-to-build-good-strings    1694