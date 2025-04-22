#pragma once

#include <vector>
#include <unordered_map>
using namespace std;

class SnapshotArray {
public:
    vector<vector<pair<int, int>>> snaps;
    int snapId = 0;

    SnapshotArray(int length) {
        for (int i = 0; i < length; i++) snaps.push_back({});
    }

    void set(int index, int val) {
        snaps[index].push_back({ snapId,val });
    }

    int snap() {
        snapId++;
        return snapId - 1;
    }

    int get(int index, int snap_id) {
        if (snaps[index].empty()) return 0;
        auto left = snaps[index].rbegin();
        auto right = snaps[index].rend();
        while (left < right) {
            auto mid = left + (right - left) / 2;
            if (mid->first >= snap_id) right = mid;
            else left = mid + 1;
        }
        if (right == snaps[index].rend()) return 0;
        else return right->second;
    }
};

// 通过 | 447ms | 186.7MB
// 思路来源：https://leetcode.cn/problems/snapshot-array/solutions/2756291/ji-lu-xiu-gai-li-shi-ha-xi-biao-er-fen-c-b1sh
// 注意：unordered_map<int,int>::iterator不支持比较大小，因此不能对一个unordered_map进行排序
// 并且对有序的map也没办法排序，因为没有其迭代器之间的operator+, operator-函数。
// 