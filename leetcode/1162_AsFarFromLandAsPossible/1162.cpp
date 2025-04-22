#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    for (vector<int>& l : grid)
        for (int& x : l) cin >> x;

    cout << maxDistance(grid) << endl;
    return 0;
}

// https://leetcode.cn/problems/as-far-from-land-as-possible/description/       1666