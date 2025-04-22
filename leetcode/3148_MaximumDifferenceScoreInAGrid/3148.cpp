#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for (vector<int>& l : grid)
        for (int& x : l) cin >> x;

    cout << maxScore(grid) << endl;
    return 0;
}

// https://leetcode.cn/problems/maximum-difference-score-in-a-grid      1820