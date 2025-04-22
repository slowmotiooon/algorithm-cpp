#pragma once

#include <queue>
#include <vector>
using namespace std;

vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    priority_queue<int, less<int>> q;
    for (int x : nums) q.push(x);
    for (int i = 0; i < k; i++) {}
}