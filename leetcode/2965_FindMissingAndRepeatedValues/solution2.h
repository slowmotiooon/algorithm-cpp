#pragma once

#include <vector>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size();
    int xorAll = 0;
    for (int i = 0; i <= n * n; i++) xorAll ^= i;
    for (vector<int> line : grid)
        for (int x : line) xorAll ^= x;
    int lowbit = xorAll & -xorAll;
    int xor1 = 0, xor0 = 0;
    int xcounter1 = 0;
    for (int i = 1; i <= n * n; i++) {
        if ((i & lowbit) == lowbit) {
            xcounter1++;
            xor1 ^= i;
        }
        else
            xor0 ^= i;
    }
    int counter1 = 0;
    for (vector<int> line : grid) {
        for (int x : line) {
            if ((x & lowbit) == lowbit) {
                counter1++;
                xor1 ^= x;
            }
            else {
                xor0 ^= x;
            }
        }
    }
    if (counter1 > xcounter1)
        return { xor1, xor0 };
    else
        return { xor0, xor1 };
}

// 通过 | 33ms | 26.05MB
// O(n) | O(1)
// 跟260题一个套路