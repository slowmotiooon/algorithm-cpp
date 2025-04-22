#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> queries(k, vector<int>(4));
    for (vector<int>& x : queries) cin >> x[0] >> x[1] >> x[2] >> x[3];

    vector<vector<int>> result = rangeAddQueries(n, queries);
    for (vector<int>& l : result)
        for (int x : l) cout << x << ' ';
    return 0;
}

// https://leetcode.cn/problems/increment-submatrices-by-one        1583