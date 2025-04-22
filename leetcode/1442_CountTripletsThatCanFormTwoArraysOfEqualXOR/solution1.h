#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

int countTriplets(vector<int>& arr) {
    int xor_ = 0;
    int ans = 0;
    unordered_map<int, int> first;
    unordered_map<int, int> val;
    val[0] = 0;
    first[0] = -1;
    for (int i = 0; i < arr.size(); i++) {
        xor_ ^= arr[i];
        if (first.find(xor_) != first.end()) {
            int a = i - first[xor_] - 1;
            ans += val[xor_] + a;
            val[xor_] = a;
        }
        else {
            first[xor_] = i;
            val[xor_] = 0;
        }
    }
    return ans;
}

// 解答错误
// 感觉离O(n)通过只有一步之遥