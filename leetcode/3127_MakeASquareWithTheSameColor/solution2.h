#pragma once

#include <vector>
using namespace std;

bool canMakeSquare(vector<vector<char>>& grid) {
    auto check = [&](int i, int j) {
        int cnt[2]{};
        cnt[grid[i][j] & 1]++;
        cnt[grid[i][j + 1] & 1]++;
        cnt[grid[i + 1][j] & 1]++;
        cnt[grid[i + 1][j + 1] & 1]++;
        return cnt[0] != 2;
        };
    return check(0, 0) || check(0, 1) || check(1, 0) || check(1, 1);
}

// 题解来自：https://leetcode.cn/problems/make-a-square-with-the-same-color/solutions/2758904/mei-ju-ji-shu-pythonjavacgo-by-endlessch-k40p/
// 1. labmda表达式
// 2. 由于'B'和'W'的ASCII值的奇偶不同，所以可以与1进行按位与(&)运算来获得cnt索引