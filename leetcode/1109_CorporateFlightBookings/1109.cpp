#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;

    vector<vector<int>> bookings(k, vector<int>(3));
    for (auto& x : bookings) cin >> x[0] >> x[1] >> x[2];

    int n;
    cin >> n;

    vector<int> ans = corpFlightBookings(bookings, n);
    return 0;
}

// https://leetcode.cn/problems/corporate-flight-bookings       1570