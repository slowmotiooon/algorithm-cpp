#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> hashTable;

    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            hashTable[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        if (hashTable.find(value) == hashTable.end()) return 0;
        right = upper_bound(hashTable[value].begin(), hashTable[value].end(), right) - hashTable[value].begin();
        left = lower_bound(hashTable[value].begin(), hashTable[value].end(), left) - hashTable[value].begin();
        return right - left;
    }

    int query2(int left, int right, int value) {
        if (hashTable.find(value) == hashTable.end()) return 0;
        int n = hashTable[value].size();
        int start = 0, end = n;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (hashTable[value][mid] > right) end = mid;
            else start = mid + 1;
        }
        start = 0;
        while (start < n) {
            int mid = start + (n - start) / 2;
            if (hashTable[value][mid] >= left) n = mid;
            else start = mid + 1;
        }
        return end - n;
    }
};

// 通过 | 558ms | 235.02MB    (query)
// 通过 | 574ms | 234.98MB    (query2)
// O(n) | O(1)      RangeFreqQuery(vector<int>& arr)
// O(logm) | O(1)   int query(int left, int right, int value), int query2(int left, int right, int value)
// 哈希表+二分
// 还有更快的？
// 更快的方法使用了C++20中的ranges::upper_bound等函数，在支持C++20的编译器上会更快。在思路上与我的方法完全相同。