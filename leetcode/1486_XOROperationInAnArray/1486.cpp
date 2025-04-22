#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n, start;
    cin >> n >> start;
    cout << xorOperation(n, start) << endl;
    return 0;
}

// https://leetcode.cn/problems/xor-operation-in-an-array/description/