#pragma once

#include <vector>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> ans;
    for (int x : asteroids) {
        if (x < 0) {
            while (!ans.empty() && ans.back() > 0 && ans.back() + x < 0) ans.pop_back();
            if (ans.empty() || ans.back() < 0) {
                ans.push_back(x);
                continue;
            }
            if (ans.back() + x == 0) {
                ans.pop_back();
                continue;
            }
        }
        else
            ans.push_back(x);
    }
    return ans;
}

// 通过 | 0ms | 21.17MB
// O(n) | O(n)