#pragma once

#include <string>
using namespace std;

int minSwaps(string s) {
    int counter = 0;
    int ans = 0;
    for (char c : s) {
        if (c == '[')
            counter++;
        else {
            if (counter == 0) {
                ans++;
                counter++;
            }
            else
                counter--;
        }
    }
    return ans;
}

// 通过 | 11ms | 33.51MB
// O(n) | O(1)
// 思路来自：https://leetcode.cn/problems/minimum-number-of-swaps-to-make-the-string-balanced/solutions/922728/go-tan-xin-by-endlesscheng-7h9n
// 涉及到贪心的思想