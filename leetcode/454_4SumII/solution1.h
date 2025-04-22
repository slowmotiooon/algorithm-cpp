#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    int n = nums1.size();
    unordered_map<int, int> counter;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            counter[-(nums1[i] + nums2[j])]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += counter[nums3[i] + nums4[j]];
        }
    }
    return ans;
}

// 通过 | 159ms | 27.91MB
// O(n^2) | O(n^2)