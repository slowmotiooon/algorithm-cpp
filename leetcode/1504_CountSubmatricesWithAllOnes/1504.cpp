#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int m, n;

    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    for (vector<int>& l : mat)
        for (int& x : l) cin >> x;

    cout << numSubmat(mat) << endl;
    return 0;
}

// https://leetcode.cn/problems/count-submatrices-with-all-ones     1845