#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (auto& l : grid)
        for (int& x : l) cin >> x;
    vector<vector<int>> moveCost(m * n, vector<int>(n));
    for (auto& l : moveCost)
        for (int& x : l) cin >> x;
    Solution* s = new Solution();
    cout << s->minPathCost(grid, moveCost) << endl;
    return 0;
}

// https://leetcode.cn/problems/minimum-path-cost-in-a-grid  1658
