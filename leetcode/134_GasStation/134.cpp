#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> gas(n), cost(n);
    for (int& x : gas) cin >> x;
    for (int& x : cost) cin >> x;

    cout << canCompleteCircuit(gas, cost) << endl;
    return 0;
}

// https://leetcode.cn/problems/gas-station/description/?envType=daily-question&envId=2024-10-06