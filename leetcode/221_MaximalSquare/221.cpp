#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> matrix(m, vector<char>(n));
    for (vector<char>& l : matrix)
        for (char& c : l) cin >> c;


    cout << maximalSquare(matrix) << endl;
    return 0;
}

// https://leetcode.cn/problems/maximal-square