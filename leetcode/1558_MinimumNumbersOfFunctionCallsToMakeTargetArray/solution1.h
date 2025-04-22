#pragma once

#include <vector>
using namespace std;

int minOperations(vector<int>& nums) {
    int operations = 0;
    while (true) {
        bool allzero = true;
        for (int& x : nums) {
            if (x != 0 && allzero) allzero = false;
            if (x & 1) {
                x -= 1;
                operations++;
            }
        }
        if (allzero) break;
        for (int& x : nums) x >>= 1;
        operations++;
    }
    return operations ? operations - 1 : 0;
}

// 通过 | 68ms | 27.38MB
// O(sigma*n) | O(1)
// 纯模拟