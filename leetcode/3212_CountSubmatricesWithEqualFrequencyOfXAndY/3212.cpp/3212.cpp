#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));
    for (vector<char>& l : grid)
        for (char& c : l) cin >> c;

    cout << numberOfSubmatrices(grid) << endl;
    return 0;
}

// https://leetcode.cn/problems/count-submatrices-with-equal-frequency-of-x-and-y       1673