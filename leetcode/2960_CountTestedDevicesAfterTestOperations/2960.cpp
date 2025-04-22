#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> batteryPercentages(n);
    for (int& x : batteryPercentages) cin >> x;

    cout << countTestedDevices(batteryPercentages) << endl;
    return 0;
}

// https://leetcode.cn/problems/count-tested-devices-after-test-operations      1169