#pragma once

#include <string>
using namespace std;

int countCollisions(string directions) {
    int ans = directions.size();
    for (char c : directions) {
        if (c == 'L')
            ans--;
        else
            break;
    }
    for (auto it = directions.rbegin(); it != directions.rend(); it++) {
        if (*it == 'R')
            ans--;
        else
            break;
    }
    for (char c : directions) {
        if (c == 'S') ans--;
    }
    return ans;
}

// 通过 | 11ms | 18.73MB
// O(n) | O(1)
// 题解来自：https://leetcode.cn/problems/count-collisions-on-a-road/solutions/1352598/jie-lun-ti-san-xing-gao-ding-by-endlessc-bvnw
