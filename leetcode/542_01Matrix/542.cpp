#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    for (vector<int>& l : mat)
        for (int& x : l) cin >> x;

    vector<vector<int>> result = updateMatrix(mat);
    for (vector<int> l : result) {
        for (int x : l) cout << x << ' ';
        cout << endl;
    }
    return 0;
}

// https://leetcode.cn/problems/01-matrix/description/