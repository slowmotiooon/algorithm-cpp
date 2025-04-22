#pragma once

#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int a = 0, b = 0;
    for (int x : nums) {
        b = (b ^ x) & ~a;
        a = (a ^ x) & ~b;
    }
    return b;
}

// 题解来自：https://leetcode.cn/problems/single-number-ii/solutions/2482832/dai-ni-yi-bu-bu-tui-dao-chu-wei-yun-suan-wnwy