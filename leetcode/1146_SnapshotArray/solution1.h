#pragma once

#include <vector>
#include <unordered_map>
using namespace std;

class SnapshotArray {
public:
    vector<unordered_map<int, int>> snaps;
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
        if (snaps[index].size() == 0) return -1;
        if (snaps[index].find(snap_id) != snaps[index].end()) return snaps[index][snap_id];
        while (snaps[index].find(snap_id) == snaps[index].end()) snap_id--;
        return snaps[index][snap_id];
    }
};

// 通过 | 1400ms | 206.6MB
// 好慢，是因为没用二分吗？