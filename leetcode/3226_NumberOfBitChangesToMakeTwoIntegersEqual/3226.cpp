#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    cout << minChanges(n, k) << endl;
    return 0;
}

// https://leetcode.cn/problems/number-of-bit-changes-to-make-two-integers-equal/description/