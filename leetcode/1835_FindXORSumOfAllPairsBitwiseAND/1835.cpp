#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> arr1(m), arr2(n);
    for (int& x : arr1) cin >> x;
    for (int& x : arr2) cin >> x;

    cout << getXORSum(arr1, arr2) << endl;
    return 0;
}

// https://leetcode.cn/problems/find-xor-sum-of-all-pairs-bitwise-and/description/      1825