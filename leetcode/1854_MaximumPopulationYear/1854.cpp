#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> logs(n, vector<int>(2));
    for (auto& x : logs) cin >> x[0] >> x[1];

    cout << maximumPopulation(logs) << endl;
    return 0;
}

// https://leetcode.cn/problems/maximum-population-year     1370