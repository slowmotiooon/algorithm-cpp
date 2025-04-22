#pragma once

#include <vector>
#include <map>
using namespace std;

class SnapshotArray {
public:
    vector<map<int, int>> snaps;
    int snapId = 0;

    SnapshotArray(int length) {
        for (int i = 0; i < length; i++) snaps.push_back({});
    }

    void set(int index, int val) {
        snaps[index][snapId] = val;
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
            auto mid = (left + left)

        }
    }
};