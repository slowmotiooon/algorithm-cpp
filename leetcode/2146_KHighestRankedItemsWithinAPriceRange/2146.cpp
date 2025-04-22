#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int m, n;

    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for (vector<int>& l : grid)
        for (int& x : l) cin >> x;

    vector<int> pricing(2);
    vector<int> start(2);

    cin >> pricing[0] >> pricing[1];
    cin >> start[0] >> start[1];

    int k;
    cin >> k;

    vector<vector<int>> ans = highestRankedKItems(grid, pricing, start, k);
    for (vector<int> l : ans) {
        for (int x : l) cout << x << ' ';
        cout << endl;
    }
    return 0;
}

// https://leetcode.cn/problems/k-highest-ranked-items-within-a-price-range/description/        1837