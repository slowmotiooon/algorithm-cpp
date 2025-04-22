#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n, capacity;
    cin >> n;

    vector<vector<int>> trips(n, vector<int>(3));
    for (vector<int>& x : trips) cin >> x[0] >> x[1] >> x[2];
    cin >> capacity;

    cout << carPooling(trips, capacity) << endl;
    return 0;
}

// https://leetcode.cn/problems/car-pooling     1441