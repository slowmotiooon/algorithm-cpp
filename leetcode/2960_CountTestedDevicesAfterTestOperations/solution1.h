#pragma once

#include <vector>
using namespace std;

int countTestedDevices(vector<int>& batteryPercentages) {
    int ans = 0;
    for (int& x : batteryPercentages)
        if (x - ans > 0) ans++;
    return ans;
}

// 通过 | 0ms | 20.23MB
// O(n) | O(1)
// 这也是差分？
