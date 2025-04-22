#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> queries(k, vector<int>(2));

    vector<int> ans = productQueries(n, queries);
    for (int x : ans) cout << x << ' ';
    return 0;
}

// https://leetcode.cn/problems/range-product-queries-of-powers