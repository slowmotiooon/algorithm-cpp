#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int m, n, k;
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    for (vector<int>& l : mat)
        for (int& x : l) cin >> x;
    cin >> k;

    vector<vector<int>> ans = matrixBlockSum(mat, k);
    for (vector<int> l : ans)
        for (int x : l) cout << x << ' ';
    cout << endl;
    return 0;
}

// https://leetcode.cn/problems/matrix-block-sum