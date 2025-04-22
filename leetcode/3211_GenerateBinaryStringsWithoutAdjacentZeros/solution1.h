#pragma once

#include <bitset>
#include <string>
#include <vector>
using namespace std;

vector<string> validStrings(int n) {
    if (n == 1) return { "0", "1" };
    int mask = (1 << n) - 1;
    vector<string> ans;
    for (int i = 2; i < (1 << n); i++) {
        int tmp = mask ^ i;
        if (((tmp >> 1) & tmp) == 0) {
            ans.push_back(bitset<18>(i).to_string().substr(18 - n));
        }
    }
    return ans;
}

// 通过 | 8ms | 11.32MB
// O(2^n) | O(1)
// 题解来自：https://leetcode.cn/problems/generate-binary-strings-without-adjacent-zeros/solutions/2833805/wei-yun-suan-zuo-fa-pythonjavacgo-by-end-6lbt
// 有思路没操作