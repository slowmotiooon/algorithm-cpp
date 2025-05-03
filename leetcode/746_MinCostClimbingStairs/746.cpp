#include "solution1.h"
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cost(n);
    for (int& x : cost) cin >> x;

    cout << minCostClimbingStairs(cost) << endl;
    return 0;
}

// https://leetcode.cn/problems/min-cost-climbing-stairs    1358
