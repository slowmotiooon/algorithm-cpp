#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> isConnected(n, vector<int>(n));
    for (vector<int>& line : isConnected)
        for (int& x : line) cin >> x;

    cout << findCircleNum(isConnected) << endl;
    return 0;
}

// https://leetcode.cn/problems/number-of-provinces/description/