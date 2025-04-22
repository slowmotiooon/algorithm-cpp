#include "solution2.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    for (vector<int>& line : grid)
        for (int& x : line) cin >> x;

    vector<int> ans = findMissingAndRepeatedValues(grid);
    for (int x : ans) cout << x << ' ';
    cout << endl;
    return 0;
}

// https://leetcode.cn/problems/find-missing-and-repeated-values/description/       1245