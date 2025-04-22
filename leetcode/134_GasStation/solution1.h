#pragma once

#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total;
    for (int i = 0; i < gas.size(); i++) {
        total = 0;
        for (int j = i; j < i + gas.size() && total >= 0; j++) {
            total += gas[j] - cost[i];
        }
        if (total >= 0) return i;
    }
    return -1;
}

// 超出时间限制
// O(n^2)做法