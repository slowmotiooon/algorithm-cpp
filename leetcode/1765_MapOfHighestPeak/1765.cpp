#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> isWater(m, vector<int>(n));
    for (vector<int>& l : isWater)
        for (int& x : l) cin >> x;

    vector<vector<int>> result = highestPeak(isWater);

    for (vector<int> l : result) {
        for (int x : l) cout << x << ' ';
        cout << endl;
    }
    return 0;
}

// https://leetcode.cn/problems/map-of-highest-peak/description/        1783