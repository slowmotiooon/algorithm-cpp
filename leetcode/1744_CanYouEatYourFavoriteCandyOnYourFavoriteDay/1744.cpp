#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> candiesCount(n);
    for (int& x : candiesCount) cin >> x;

    vector<vector<int>> queries(k, vector<int>(3));
    for (vector<int>& x : queries) cin >> x[0] >> x[1] >> x[2];

    vector<bool> ans = canEat(candiesCount, queries);
    for (bool x : ans) cout << x << " ";
    cout << endl;
    return 0;
}

// https://leetcode.cn/problems/can-you-eat-your-favorite-candy-on-your-favorite-day        1859