#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    cout << hammingDistance(x, y) << endl;
    return 0;
}

// https://leetcode.cn/problems/hamming-distance/description/