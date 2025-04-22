#pragma once

#include <vector>
using namespace std;

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> diff(n + 2, 0);
    for (auto& x : bookings) {
        diff[x[0]] += x[2];
        diff[x[1] + 1] -= x[2];
    }
    vector<int> ans(n, 0);
    for (int i = 1; i < n + 1; i++) {
        if (i == 1)
            ans[i - 1] = diff[i];
        else
            ans[i - 1] = ans[i - 2] + diff[i];
    }
    return ans;
}

// 通过 | 4ms | 70.52MB
// O(n) | O(n)
// 经典差分